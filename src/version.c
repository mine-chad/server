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

void printf_version(void) {
    printf(
           "Mine-chad server version %s" /* version number */                               "\n"
                                                                                            "\n"
           "Copyright (C) 2023 Mine-chad"                                                   "\n"
           "This software is licensed under the MIT terms: <https://mit-license.org/>."     "\n"
           "This is free software: you are free to change and redistribute it."             "\n"
           "There is NO WARRANTY, to the extent permitted by law."                          "\n"
                                                                                            "\n"
          , VERSION_STR);
}
