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

#include <stdio.h>

#include "info.h"

void printf_help(void) {
    printf(                                                                                 "\n"
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
}

void printf_version() {
    printf(
            "Mine-chad server %s",
            VERSION_STR
            );
}
