/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/code/app.h"
#include <unistd.h> // For STDOUT_FILENO


bool app_entry(int argc, char** argv) {
    if (argc < 2) {
        fossil_io_printf("{blue,bold}Usage:{cyan} shark <command> [options]{reset}\n");
        return EXIT_FAILURE;
    }

    const char *arg1 = argv[1];

    // Handle flags (must start with "--")
    if (arg1[0] == '-' && arg1[1] == '-') {
        if (fossil_io_cstring_compare(arg1, "--help") == 0) {
            handle_help();
            return EXIT_SUCCESS;
        } else if (fossil_io_cstring_compare(arg1, "--version") == 0) {
            handle_version();
            return EXIT_SUCCESS;
        } else if (fossil_io_cstring_compare(arg1, "--name") == 0) {
            handle_name();
            return EXIT_SUCCESS;
        } else if (fossil_io_cstring_compare(arg1, "--verbose") == 0) {
            ENABLE_VERBOSE = true;
            fossil_io_printf("{cyan}Verbose mode enabled.{reset}\n");
            return EXIT_SUCCESS;
        } else {
            fossil_io_printf("{red}Unknown flag: %s{reset}\n", arg1);
            handle_help();
            return EXIT_FAILURE;
        }
    }

    // Handle color option: "color=<option>"
    if (strncmp(arg1, "color=", 6) == 0) {
        const char *color_option = arg1 + 6;
        if (fossil_io_cstring_compare(color_option, "enable") == 0) {
            FOSSIL_IO_COLOR_ENABLE = true;
            fossil_io_printf("{green}Color output enabled.{reset}\n");
        } else if (fossil_io_cstring_compare(color_option, "disable") == 0) {
            FOSSIL_IO_COLOR_ENABLE = false;
            fossil_io_printf("{yellow}Color output disabled.{reset}\n");
        } else if (fossil_io_cstring_compare(color_option, "auto") == 0) {
            FOSSIL_IO_COLOR_ENABLE = isatty(STDOUT_FILENO);
            fossil_io_printf("{cyan}Color output set to auto-detect.{reset}\n");
        } else {
            fossil_io_printf("{red}Invalid color option. Use enable, disable, or auto.{reset}\n");
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

    // Parse commands
    if (fossil_io_cstring_compare(arg1, "move") == 0) {
        if (argc < 4) {
            fossil_io_printf("{blue}Usage:{cyan} shark move <source> <destination>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_move(argv[2], argv[3]);
    } else if (fossil_io_cstring_compare(arg1, "copy") == 0) {
        if (argc < 4) {
            fossil_io_printf("{blue}Usage:{cyan} shark copy <source> <destination>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_copy(argv[2], argv[3]);
    } else if (fossil_io_cstring_compare(arg1, "delete") == 0) {
        if (argc < 3) {
            fossil_io_printf("{blue}Usage:{cyan} shark delete <target>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_delete(argv[2]);
    } else if (fossil_io_cstring_compare(arg1, "list") == 0) {
        if (argc < 3) {
            fossil_io_printf("{blue}Usage:{cyan} shark list <directory>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_list(argv[2]);
    } else if (fossil_io_cstring_compare(arg1, "show") == 0) {
        if (argc < 3) {
            fossil_io_printf("{blue}Usage:{cyan} shark show <file>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_show(argv[2]);
    } else if (fossil_io_cstring_compare(arg1, "find") == 0) {
        if (argc < 4) {
            fossil_io_printf("{blue}Usage:{cyan} shark find <directory> <pattern>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_find(argv[2], argv[3]);
    } else if (fossil_io_cstring_compare(arg1, "search") == 0) {
        if (argc < 4) {
            fossil_io_printf("{blue}Usage:{cyan} shark search <file> <pattern>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_search(argv[2], argv[3]);
    } else if (fossil_io_cstring_compare(arg1, "size") == 0) {
        if (argc < 3) {
            fossil_io_printf("{blue}Usage:{cyan} shark size <target>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_size(argv[2]);
    } else if (fossil_io_cstring_compare(arg1, "disk") == 0) {
        if (argc < 3) {
            fossil_io_printf("{blue}Usage:{cyan} shark disk <path>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_disk(argv[2]);
    } else if (fossil_io_cstring_compare(arg1, "tree") == 0) {
        if (argc < 3) {
            fossil_io_printf("{blue}Usage:{cyan} shark tree <directory>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_tree(argv[2]);
    } else if (fossil_io_cstring_compare(arg1, "compare") == 0) {
        if (argc < 4) {
            fossil_io_printf("{blue}Usage:{cyan} shark compare <path1> <path2>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_compare(argv[2], argv[3]);
    } else if (fossil_io_cstring_compare(arg1, "create") == 0) {
        if (argc < 3) {
            fossil_io_printf("{blue}Usage:{cyan} shark create <target>{reset}\n");
            return EXIT_FAILURE;
        }
        handle_create(argv[2]);
    } else if (fossil_io_cstring_compare(arg1, "clear") == 0) {
        fossil_io_clear_screen();
    } else if (fossil_io_cstring_compare(arg1, "color=") == 0) {
        if (argc < 3) {
            fossil_io_printf("{blue}Usage:{cyan} shark color=<enable|disable|auto>{reset}\n");
            return EXIT_FAILURE;
        }

        const char *color_option = argv[2];
        if (fossil_io_cstring_compare(color_option, "enable") == 0) {
            FOSSIL_IO_COLOR_ENABLE = true;
            fossil_io_printf("{green}Color output enabled.{reset}\n");
        } else if (fossil_io_cstring_compare(color_option, "disable") == 0) {
            FOSSIL_IO_COLOR_ENABLE = false;
            fossil_io_printf("{yellow}Color output disabled.{reset}\n");
        } else if (fossil_io_cstring_compare(color_option, "auto") == 0) {
            FOSSIL_IO_COLOR_ENABLE = isatty(STDOUT_FILENO);
            fossil_io_printf("{cyan}Color output set to auto-detect.{reset}\n");
        } else {
            fossil_io_printf("{red}Invalid color option. Use enable, disable, or auto.{reset}\n");
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;

    } else {
        fossil_io_printf("{red}Unknown command: %s{reset}\n", arg1);
        handle_help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}