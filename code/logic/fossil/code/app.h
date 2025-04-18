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
#ifndef FOSSIL_APP_CODE_H
#define FOSSIL_APP_CODE_H

#include <fossil/sys/framework.h>
#include <fossil/io/framework.h>

#define FOSSIL_APP_NAME "Shark"
#define FOSSIL_APP_VERSION "0.1.0"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Opens a file with the specified mode.
 * 
 * @param filename The name of the file to open.
 * @param mode The mode in which to open the file (e.g., "r", "w").
 * @return 0 on success, non-zero on failure.
 */
int cmd_open(const char *filename, const char *mode);

/**
 * @brief Copies the contents of one file to another.
 * 
 * @param src The source file path.
 * @param dst The destination file path.
 * @return 0 on success, non-zero on failure.
 */
int cmd_copy(const char *src, const char *dst);

/**
 * @brief Appends data to the end of a file.
 * 
 * @param filename The name of the file to append to.
 * @param data The data to append to the file.
 * @return 0 on success, non-zero on failure.
 */
int cmd_append(const char *filename, const char *data);

/**
 * @brief Displays information about a file.
 * 
 * @param filename The name of the file to inspect.
 * @return 0 on success, non-zero on failure.
 */
int cmd_info(const char *filename);

/**
 * @brief Removes a file from the filesystem.
 * 
 * @param filename The name of the file to remove.
 * @return 0 on success, non-zero on failure.
 */
int cmd_remove(const char *filename);

/**
 * @brief Creates a backup of a file with a specified suffix.
 * 
 * @param filename The name of the file to back up.
 * @param suffix The suffix to append to the backup file name.
 * @return 0 on success, non-zero on failure.
 */
int cmd_backup(const char *filename, const char *suffix);

/**
 * @brief Reads and displays the contents of a file.
 * 
 * @param filename The name of the file to read.
 * @return 0 on success, non-zero on failure.
 */
int cmd_read(const char *filename);

/**
 * @brief Writes data to a file, overwriting its contents.
 * 
 * @param filename The name of the file to write to.
 * @param data The data to write to the file.
 * @return 0 on success, non-zero on failure.
 */
int cmd_write(const char *filename, const char *data);

/**
 * @brief Renames a file from an old name to a new name.
 * 
 * @param oldname The current name of the file.
 * @param newname The new name for the file.
 * @return 0 on success, non-zero on failure.
 */
int cmd_rename(const char *oldname, const char *newname);

/**
 * @brief Custom application entry point.
 * This function is the main entry point for the custom application.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return 0 if the application runs successfully, non-zero otherwise.
 */
bool app_entry(int argc, char** argv);


#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_APP_CODE_H */
