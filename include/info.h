/*
 * Copyright (C) 2023-2024 mine-chad
 *
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

#ifndef VERSION_H
# define VERSION_H


/**
 * @brief The version string
 *
 * Defines the version - as a string, not a floating number!
 */
# ifndef VERSION_STR
#  define VERSION_STR "0.0.0"
# endif /* VERSION_STR */


/**
 * @brief Turns on debug logging when true.
 *
 * By default, DEBUG should be false.
 *
 * If you want to debug literally everything, set DEBUG as true.
 * Otherwise, set DEBUG as false.
 *
 * NOTE: When compiling as "Release", always check this to be set to false
 */
#ifndef DEBUG
# define DEBUG false
#endif /* DEBUG */

void printf_version(void);
void printf_help(void);

#endif /* VERSION_H */
