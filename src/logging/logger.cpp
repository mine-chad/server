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

#include "logger.h"

void logger::log(logger::Level level, const char *message) {
    switch(level) {
        case _LOG_DEBUG:
            std::cout << color::RGB{0, 255, 255} << "[" << _internal::getTime() << "/DEBUG] " << message << color::RGB{255, 255, 255} << std::endl;
            break;
        case _LOG_INFO:
            std::cout << color::RGB{0, 255, 0} << "[" << _internal::getTime() << "/INFO] " << message << color::RGB{255, 255, 255} << std::endl;
            break;
        case _LOG_WARN:
            std::cout << color::RGB{255, 255, 0} << "[" << _internal::getTime() << "/WARN] " << message << color::RGB{255, 255, 255} << std::endl;
            break;
        case _LOG_ERROR:
            std::cout << color::RGB{255, 85, 85} << "[" << _internal::getTime() << "/ERROR] " << message << color::RGB{255, 255, 255} << std::endl;
            break;
        case _LOG_FATAL:
            std::cout << color::RGB{170, 0, 0} << "[" << _internal::getTime() << "/FATAL] " << message << color::RGB{255, 255, 255} << std::endl;
            break;
    }
}

char *logger::_internal::getTime() {
    time_t rawtime;
    struct tm *timeinfo;
    char *buffer = new char[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "%F %T", timeinfo);

    return buffer;
}
