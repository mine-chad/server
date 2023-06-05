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

#ifndef MINECHAD_LOGGER_H
#define MINECHAD_LOGGER_H

#include <ctime>
#include "color.h"

namespace logger {
    namespace _internal {
        char* getTime();
    };

    void debug(const char *message);
    void info(const char *message);
    void warn(const char *message);
    void error(const char *message);
    void fatal(const char *message);
};

#endif //MINECHAD_LOGGER_H
