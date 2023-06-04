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
#include <errno.h>
#include <signal.h>
#include <getopt.h>

#include "info.h"
#include "term_handler.h"

int main(int argc, char *argv[]) {

    /* Set up a handler for the SIGTERM and SIGINT signal */
    signal(SIGTERM, term_handler);
    signal(SIGINT, term_handler);

    /* Hello World - very important :D */
    std::cout << "Hello, world!" << std::endl;

    /* Struct argument options - getopt_long style */
    static struct option long_options [] = {
      { "help"                , no_argument      , NULL , 'h' },
      { "version"             , no_argument      , NULL , 'v' },
      { NULL                  , 0                , NULL , 0   }
    };
    /* Check for arguments */
    while(1) {
        int c = getopt_long(argc, argv, "ht:vDf:d:c:S:", long_options, NULL);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch(c) {
            /* help */
            case 'h':
                printf_help();
                exit(EXIT_SUCCESS);
                break;

            /* version */
            case 'v':
                printf_version();
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

    /* Last resort return */
    return 0;
}
