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
#include <fossil/test/framework.h>

#include "fossil/code/app.h"


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define the test suite and add test cases
FOSSIL_TEST_SUITE(c_test_app_suite);
fossil_fstream_t fstream;

// Setup function for the test suite
FOSSIL_SETUP(c_test_app_suite) {
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_test_app_suite) {
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_app_name) {
    const char *app_name = FOSSIL_APP_NAME;
    ASSUME_ITS_EQUAL_CSTR("Shark", app_name);
}

FOSSIL_TEST_CASE(c_test_app_version) {
    const char *app_version = FOSSIL_APP_VERSION;
    ASSUME_ITS_EQUAL_CSTR("0.1.0", app_version);
}
FOSSIL_TEST_CASE(c_test_cmd_open) {
    fossil_fstream_open(&fstream, "testfile.txt", "w");
    ASSUME_NOT_CNULL(&fstream);
    int32_t result = cmd_open("testfile.txt", "w");
    ASSUME_ITS_EQUAL_I32(0, result);
    fossil_fstream_close(&fstream);
}

FOSSIL_TEST_CASE(c_test_cmd_copy) {
    fossil_fstream_open(&fstream, "source.txt", "w");
    ASSUME_NOT_CNULL(&fstream);
    fossil_fstream_close(&fstream);

    int32_t result = cmd_copy("source.txt", "destination.txt");
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST_CASE(c_test_cmd_append) {
    fossil_fstream_open(&fstream, "testfile.txt", "w");
    ASSUME_NOT_CNULL(&fstream);
    fossil_fstream_close(&fstream);

    int32_t result = cmd_append("testfile.txt", "Sample data");
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST_CASE(c_test_cmd_info) {
    fossil_fstream_open(&fstream, "testfile.txt", "w");
    ASSUME_NOT_CNULL(&fstream);
    fossil_fstream_close(&fstream);

    int32_t result = cmd_info("testfile.txt");
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST_CASE(c_test_cmd_remove) {
    fossil_fstream_open(&fstream, "testfile.txt", "w");
    ASSUME_NOT_CNULL(&fstream);
    fossil_fstream_close(&fstream);

    int32_t result = cmd_remove("testfile.txt");
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST_CASE(c_test_cmd_backup) {
    fossil_fstream_open(&fstream, "testfile.txt", "w");
    ASSUME_NOT_CNULL(&fstream);
    fossil_fstream_close(&fstream);

    int32_t result = cmd_backup("testfile.txt", ".bak");
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST_CASE(c_test_cmd_read) {
    fossil_fstream_open(&fstream, "testfile.txt", "w");
    ASSUME_NOT_CNULL(&fstream);
    fossil_fstream_close(&fstream);

    int32_t result = cmd_read("testfile.txt");
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST_CASE(c_test_cmd_write) {
    fossil_fstream_open(&fstream, "testfile.txt", "w");
    ASSUME_NOT_CNULL(&fstream);
    fossil_fstream_close(&fstream);

    int32_t result = cmd_write("testfile.txt", "Sample data");
    ASSUME_ITS_EQUAL_I32(0, result);
}

FOSSIL_TEST_CASE(c_test_cmd_rename) {
    fossil_fstream_open(&fstream, "oldname.txt", "w");
    ASSUME_NOT_CNULL(&fstream);
    fossil_fstream_close(&fstream);

    int32_t result = cmd_rename("oldname.txt", "newname.txt");
    ASSUME_ITS_EQUAL_I32(0, result);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_test_app_tests) {
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_app_name);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_app_version);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_cmd_open);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_cmd_copy);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_cmd_append);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_cmd_info);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_cmd_remove);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_cmd_backup);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_cmd_read);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_cmd_write);
    FOSSIL_TEST_ADD(c_test_app_suite, c_test_cmd_rename);

    FOSSIL_TEST_REGISTER(c_test_app_suite);
}
