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

int cmd_open(const char *filename, const char *mode) {
    fossil_fstream_t stream;
    if (fossil_fstream_open(&stream, filename, mode) == 0) {
        printf("File opened: %s\n", stream.filename);
        fossil_fstream_close(&stream);
        return FOSSIL_IO_SUCCESS;
    }
    fprintf(stderr, "Failed to open file: %s\n", filename);
    return FOSSIL_IO_FAILURE;
}

int cmd_copy(const char *src, const char *dst) {
    fossil_fstream_t src_stream, dst_stream;
    if (fossil_fstream_open(&src_stream, src, "rb") != 0) {
        fprintf(stderr, "Failed to open source file: %s\n", src);
        return FOSSIL_IO_FAILURE;
    }
    if (fossil_fstream_open(&dst_stream, dst, "wb") != 0) {
        fprintf(stderr, "Failed to open destination file: %s\n", dst);
        fossil_fstream_close(&src_stream);
        return FOSSIL_IO_FAILURE;
    }

    char buffer[1024];
    size_t n;
    while ((n = fossil_fstream_read(&src_stream, buffer, 1, sizeof(buffer))) > 0) {
        fossil_fstream_write(&dst_stream, buffer, 1, n);
    }

    fossil_fstream_close(&src_stream);
    fossil_fstream_close(&dst_stream);
    printf("Copied %s to %s\n", src, dst);
    return FOSSIL_IO_SUCCESS;
}

int cmd_append(const char *filename, const char *data) {
    fossil_fstream_t stream;
    if (fossil_fstream_open(&stream, filename, "a") != 0) {
        fprintf(stderr, "Could not open file for appending.\n");
        return FOSSIL_IO_FAILURE;
    }
    if (fossil_fstream_append(&stream, data, 1, strlen(data)) == 0) {
        printf("Appended data to %s\n", filename);
        fossil_fstream_close(&stream);
        return FOSSIL_IO_SUCCESS;
    }
    fprintf(stderr, "Append failed.\n");
    fossil_fstream_close(&stream);
    return FOSSIL_IO_FAILURE;
}


int cmd_info(const char *filename) {
    if (!fossil_fstream_file_exists(filename)) {
        printf("File does not exist.\n");
        return FOSSIL_IO_FAILURE;
    }

    printf("File: %s\n", filename);
    printf("Readable: %s\n", fossil_fstream_is_readable(filename) ? "yes" : "no");
    printf("Writable: %s\n", fossil_fstream_is_writable(filename) ? "yes" : "no");
    printf("Executable: %s\n", fossil_fstream_is_executable(filename) ? "yes" : "no");

    fossil_fstream_t stream;
    if (fossil_fstream_open(&stream, filename, "rb") == 0) {
        int32_t size = fossil_fstream_get_size(&stream);
        printf("Size: %d bytes\n", size);
        fossil_fstream_close(&stream);
    } else {
        printf("Could not determine file size.\n");
    }

    return FOSSIL_IO_SUCCESS;
}

int cmd_remove(const char *filename) {
    if (fossil_fstream_remove(filename) == 0) {
        printf("Removed file: %s\n", filename);
        return FOSSIL_IO_SUCCESS;
    }
    fprintf(stderr, "Failed to remove file: %s\n", filename);
    return FOSSIL_IO_FAILURE;
}

int cmd_backup(const char *filename, const char *suffix) {
    if (fossil_fstream_backup(filename, suffix) == 0) {
        printf("Backup created: %s\n", filename);
        return FOSSIL_IO_SUCCESS;
    }
    fprintf(stderr, "Failed to create backup for: %s\n", filename);
    return FOSSIL_IO_FAILURE;
}

int cmd_read(const char *filename) {
    fossil_fstream_t stream;
    if (fossil_fstream_open(&stream, filename, "r") != 0) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return FOSSIL_IO_FAILURE;
    }

    char buffer[1024];
    size_t n;
    while ((n = fossil_fstream_read(&stream, buffer, 1, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    fossil_fstream_close(&stream);
    printf("\n");
    return FOSSIL_IO_SUCCESS;
}

int cmd_write(const char *filename, const char *data) {
    fossil_fstream_t stream;
    if (fossil_fstream_open(&stream, filename, "w") != 0) {
        fprintf(stderr, "Could not open file for writing: %s\n", filename);
        return FOSSIL_IO_FAILURE;
    }
    if (fossil_fstream_write(&stream, data, 1, strlen(data)) != 0) {
        printf("Wrote data to %s\n", filename);
        fossil_fstream_close(&stream);
        return FOSSIL_IO_SUCCESS;
    }
    fprintf(stderr, "Write failed.\n");
    fossil_fstream_close(&stream);
    return FOSSIL_IO_FAILURE;
}

int cmd_rename(const char *oldname, const char *newname) {
    if (fossil_fstream_rename(oldname, newname) == 0) {
        printf("Renamed %s to %s\n", oldname, newname);
        return FOSSIL_IO_SUCCESS;
    }
    fprintf(stderr, "Failed to rename file.\n");
    return FOSSIL_IO_FAILURE;
}

bool app_entry(int argc, char** argv) {
    fossil_io_printf("[shark] Entry\n");

    if (argc < 2) {
        fprintf(stderr, "Usage: fossil_file <command> [...]\n");
        return FOSSIL_IO_FAILURE;
    }

    const char *cmd = argv[1];

    if (strcmp(cmd, "--help") == 0 || strcmp(cmd, "-h") == 0) {
        printf("Shark — Available Commands:\n");
        printf("  --help, -h                Show this help message\n");
        printf("  --version, -v             Show version information\n");
        printf("  open <file> <mode>        Open a file with specified mode\n");
        printf("  copy <src> <dst>          Copy file from src to dst\n");
        printf("  append <file> <data>      Append string data to a file\n");
        printf("  info <file>               Show info about a file\n");
        printf("  remove <file>             Delete a file\n");
        printf("  backup <file> <suffix>    Backup a file with suffix\n");
        printf("  read <file>               Read a file and print its contents\n");
        printf("  write <file> <data>       Write data to a file\n");
        printf("  rename <oldname> <newname> Rename a file\n");

        return FOSSIL_IO_SUCCESS;
    }

    if (strcmp(cmd, "--version") == 0 || strcmp(cmd, "-v") == 0) {
        printf("Fossil File CLI version %s\n", FOSSIL_APP_VERSION);
        return FOSSIL_IO_SUCCESS;
    }

    if (strcmp(cmd, "open") == 0 && argc == 4) {
        return cmd_open(argv[2], argv[3]);
    } else if (strcmp(cmd, "copy") == 0 && argc == 4) {
        return cmd_copy(argv[2], argv[3]);
    } else if (strcmp(cmd, "append") == 0 && argc == 4) {
        return cmd_append(argv[2], argv[3]);
    } else if (strcmp(cmd, "info") == 0 && argc == 3) {
        return cmd_info(argv[2]);
    } else if (strcmp(cmd, "remove") == 0 && argc == 3) {
        return cmd_remove(argv[2]);
    } else if (strcmp(cmd, "backup") == 0 && argc == 4) {
        return cmd_backup(argv[2], argv[3]);
    }     else if (strcmp(cmd, "read") == 0 && argc == 3) {
        return cmd_read(argv[2]);
    } else if (strcmp(cmd, "write") == 0 && argc == 4) {
        return cmd_write(argv[2], argv[3]);
    } else if (strcmp(cmd, "rename") == 0 && argc == 4) {
        return cmd_rename(argv[2], argv[3]);
    }

    fprintf(stderr, "Unknown or malformed command. Use --help for usage.\n");
    return FOSSIL_IO_FAILURE;
}
