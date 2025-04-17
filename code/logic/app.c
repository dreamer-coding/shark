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
#include "fossil/code/lifecycle.h"


void custom_app_on_create(fossil_app_engine_t* app) {
    fossil_io_printf("App Created\n");
    app->state = FOSSIL_APP_LIFECYCLE_STATE_CREATED;
}

void custom_app_on_start(fossil_app_engine_t* app) {
    fossil_io_printf("App Started\n");
    app->state = FOSSIL_APP_LIFECYCLE_STATE_STARTED;
}

void custom_app_on_resume(fossil_app_engine_t* app) {
    fossil_io_printf("App Resumed\n");
    app->state = FOSSIL_APP_LIFECYCLE_STATE_RESUMED;
}

void custom_app_on_pause(fossil_app_engine_t* app) {
    fossil_io_printf("App Paused\n");
    app->state = FOSSIL_APP_LIFECYCLE_STATE_PAUSED;
}

void custom_app_on_timeout(fossil_app_engine_t* app) {
    fossil_io_printf("App Timed Out\n");
    app->state = FOSSIL_APP_LIFECYCLE_STATE_TIMEOUT;
}

void custom_app_on_stop(fossil_app_engine_t* app) {
    fossil_io_printf("App Stopped\n");
    app->state = FOSSIL_APP_LIFECYCLE_STATE_STOPPED;
}

void custom_app_on_destroy(fossil_app_engine_t* app) {
    fossil_io_printf("App Destroyed\n");
    app->state = FOSSIL_APP_LIFECYCLE_STATE_DESTROYED;
}

bool app_entry(int argc, char** argv) {
    unused(argc);
    unused(argv);

    fossil_io_printf("Launching Custom App...\n");

    fossil_app_engine_t app;
    fossil_app_init(&app);

    app.on_create  = custom_app_on_create;
    app.on_start   = custom_app_on_start;
    app.on_resume  = custom_app_on_resume;
    app.on_pause   = custom_app_on_pause;
    app.on_timeout = custom_app_on_timeout;
    app.on_stop    = custom_app_on_stop;
    app.on_destroy = custom_app_on_destroy;

    // Optional: custom transition handler (if you want custom rules)
    // app.transition = your_custom_transition_handler;

    fossil_app_run(&app);
    return 0;
}
