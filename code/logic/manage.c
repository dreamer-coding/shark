/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/code/commands.h"

/**
 * Internal helper: prints current permissions for a user or group
 */
static void print_permissions(ccstring name, bool is_group) {
    char permfile[512];
    snprintf(permfile, sizeof(permfile), "/etc/fossil-perms/%s_%s.perm", is_group ? "group" : "user", name);

    int32_t mode = 0;
    if (fossil_io_file_get_permissions(permfile, &mode) == 0) {
        fossil_io_file_t pf;
        if (fossil_io_file_open(&pf, permfile, "r") == 0) {
            char perms[256] = {0};
            fossil_io_file_read(&pf, perms, 1, sizeof(perms) - 1);
            fossil_io_file_close(&pf);
            char type[8];
            snprintf(type, sizeof(type), "%s", is_group ? "Group" : "User");
            fossil_io_printf("{cyan}%s{reset} '{yellow}%s{reset}' has permissions: {green}%s{reset}\n", type, name, perms);
        } else {
            fossil_io_printf("{red}Could not open permissions file for %s '{yellow}%s{reset}'\n", is_group ? "group" : "user", name);
        }
    } else {
        fossil_io_printf("{red}No permissions found for %s '{yellow}%s{reset}'\n", is_group ? "group" : "user", name);
    }
}

/**
 * Internal helper: modify permissions
 */
static int modify_permission(ccstring name, ccstring perm, bool add, bool is_group) {
    if (!perm || !name) return -1;

    char permfile[512];
    snprintf(permfile, sizeof(permfile), "/etc/fossil-perms/%s_%s.perm", is_group ? "group" : "user", name);

    fossil_io_file_t pf;
    char perms[256] = {0};
    size_t len = 0;

    if (fossil_io_file_open(&pf, permfile, "r+") == 0) {
        len = fossil_io_file_read(&pf, perms, 1, sizeof(perms) - 1);
        perms[len] = '\0';
        fossil_io_file_rewind(&pf);
    } else {
        if (fossil_io_file_open(&pf, permfile, "w+") != 0)
            return -1;
    }

    char *found = strstr(perms, perm);
    if (add && !found) {
        if (strlen(perms) > 0) strcat(perms, ",");
        strcat(perms, perm);
    } else if (!add && found) {
        char *end = found + strlen(perm);
        if (*end == ',') ++end;
        memmove(found, end, strlen(end) + 1);
        size_t plen = strlen(perms);
        if (plen > 0 && perms[plen - 1] == ',') perms[plen - 1] = '\0';
    }

    fossil_io_file_rewind(&pf);
    fossil_io_file_write(&pf, perms, 1, strlen(perms));
    fossil_io_file_close(&pf);

    fossil_io_printf("{%s}%s permission '{yellow}%s{reset}' %s for %s '{cyan}%s{reset}'\n",
        add ? "green" : "red",
        add ? "Adding" : "Removing",
        perm,
        add ? "added" : "removed",
        is_group ? "group" : "user",
        name);

    return 0;
}

/**
 * Manage user and group permissions.
 * @param user Name of the user (NULL if not specified)
 * @param group Name of the group (NULL if not specified)
 * @param add_perm Permission to add (NULL if not specified)
 * @param remove_perm Permission to remove (NULL if not specified)
 * @param list List permissions if true
 * @param set_perm Set permissions explicitly (NULL if not specified)
 * @return 0 on success, non-zero on error
 */
int fossil_shark_manage(ccstring user, ccstring group,
                        ccstring add_perm, ccstring remove_perm,
                        bool list, ccstring set_perm) {
    int rc = 0;

    if (user == NULL && group == NULL) {
        fossil_io_printf("{red,bold}Error:{reset} Either user or group must be specified.\n");
        return -1;
    }

    if (list) {
        if (user) print_permissions(user, false);
        if (group) print_permissions(group, true);
    }

    if (set_perm) {
        if (user) {
            char permfile[512];
            snprintf(permfile, sizeof(permfile), "/etc/fossil-perms/user_%s.perm", user);
            fossil_io_file_t pf;
            if (fossil_io_file_open(&pf, permfile, "w") == 0) {
                fossil_io_file_write(&pf, set_perm, 1, strlen(set_perm));
                fossil_io_file_close(&pf);
                fossil_io_printf("Setting permissions for user '{yellow}%s{reset}' to '{green}%s{reset}'\n", user, set_perm);
            } else {
                fossil_io_printf("{red}Failed to set permissions for user '{yellow}%s{reset}'\n", user);
                rc |= 1;
            }
        }
        if (group) {
            char permfile[512];
            snprintf(permfile, sizeof(permfile), "/etc/fossil-perms/group_%s.perm", group);
            fossil_io_file_t pf;
            if (fossil_io_file_open(&pf, permfile, "w") == 0) {
                fossil_io_file_write(&pf, set_perm, 1, strlen(set_perm));
                fossil_io_file_close(&pf);
                fossil_io_printf("Setting permissions for group '{yellow}%s{reset}' to '{green}%s{reset}'\n", group, set_perm);
            } else {
                fossil_io_printf("{red}Failed to set permissions for group '{yellow}%s{reset}'\n", group);
                rc |= 1;
            }
        }
    }

    if (add_perm) {
        if (user) rc |= modify_permission(user, add_perm, true, false);
        if (group) rc |= modify_permission(group, add_perm, true, true);
    }

    if (remove_perm) {
        if (user) rc |= modify_permission(user, remove_perm, false, false);
        if (group) rc |= modify_permission(group, remove_perm, false, true);
    }

    return rc;
}
