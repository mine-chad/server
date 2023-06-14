/*
 * Copyright (C) 2023 mine-chad
 * This file is part of the Mine-chad project.
 *
 * Mine-chad is free software: you can redistribute it and/or modify it under
 * the terms of the MIT License.
 *
 * Mine-chad is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the MIT License for more details.
 *
 * You should have received a copy of the MIT License along with Mine-chad. If
 * not, see <https://mit-license.org/> or contact the Massachusetts Institute
 * of Technology (MIT) at <tlo-inquiries@mit.edu>.
 */

#include <iostream>

#include <csignal>
#include <getopt.h>

#include "info.h"
#include "logging/logger.h"

void shutdown();
void interrupt_handler(int signal);

int main(int argc, char *argv[]) {
    logger::init();

    /* Set up a handler for the SIGTERM and SIGINT signal */
    signal(SIGTERM, interrupt_handler);
    signal(SIGINT, interrupt_handler);

    /* Hello World - very important :D */
    logger::info("Hello world!");

    /* Struct argument options - getopt_long style */
    static struct option long_options [] = {
      { "help"                , no_argument      , NULL , 'h' },
      { "version"             , no_argument      , NULL , 'v' },
      { NULL                  , 0                , NULL , 0   }
    };
    /* Check for arguments */
    while(true) {
        int c = getopt_long(argc, argv, "ht:vDf:d:c:S:", long_options, NULL);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch(c) {
            /* help */
            case 'h':
                printf(
                        "\n"
                        "Mine-chad server"                                                               "\n"
                        "Server for the Mine-chad sandbox open-world game."                              "\n"
                        "\n"
                        "Usage: mine-chad-server [options]"                                              "\n"
                        "\n"
                        "Options:"                                                                       "\n"
                        "-h, --help\t\t\t"              "Output this help list and exit"                 "\n"
                        "-v, --version\t\t\t"           "Output version information and license and exit""\n"
                        "-D, --debug\t\t\t"             "Output the debug log"                           "\n"
                        "\n"
                        "Note that Mine-chad is still under heavy development."                          "\n"
                );
                exit(EXIT_SUCCESS);
                break;

            /* version */
            case 'v':
                printf(
                        "Mine-chad server %s",
                        VERSION_STR
                );
                exit(EXIT_SUCCESS);
                break;

            case '?':
                /* No need to print and error message because
                   getopt_long did that already. */
                exit(EXIT_FAILURE);
                break;

            default:
                abort();
        }
    }

    shutdown();

    /* Last resort return */

    return 0;
}

void shutdown() {
    logger::info("Shutting down...");

    logger::close();

    exit(EXIT_SUCCESS);
}

void interrupt_handler(int signal) {
    logger::warn("Interrupt signal received");
    shutdown();
}
