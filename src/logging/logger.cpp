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
#include "../info.h"
#include <fstream>

std::ofstream f_out;

void logger::init() {
    f_out.open("mine-chad.log", std::ios::out | std::ios::app);
    if (!f_out.is_open()) {
        std::cout << color::RGB{255, 0, 0} << "[" << _internal::getTime() << "/FATAL] Failed to open log file." << color::RGB{255, 255, 255} << std::endl;
        std::cout << color::RGB{255, 0, 0} << "[" << _internal::getTime() << "/FATAL] Exiting..." << color::RGB{255, 255, 255} << std::endl;
        exit(1);
    }
}

void logger::close() {
    f_out.close();
}

void logger::debug(const char *message) {
    if (!DEBUG) return;
    std::cout << color::RGB{0, 255, 255} << "[" << _internal::getTime() << "/DEBUG] " << message << color::RGB{255, 255, 255} << std::endl;
    f_out << "[" << _internal::getTime() << "/DEBUG] " << message << std::endl;
}

void logger::info(const char *message) {
    std::cout << color::RGB{0, 255, 0} << "[" << _internal::getTime() << "/INFO] " << message << color::RGB{255, 255, 255} << std::endl;
    f_out << "[" << _internal::getTime() << "/INFO] " << message << std::endl;
}

void logger::warn(const char *message) {
    std::cout << color::RGB{255, 255, 0} << "[" << _internal::getTime() << "/WARN] " << message << color::RGB{255, 255, 85} << std::endl;
    f_out << "[" << _internal::getTime() << "/WARN] " << message << std::endl;
}

void logger::error(const char *message) {
    std::cout << color::RGB{255, 85, 85} << "[" << _internal::getTime() << "/ERROR] " << message << color::RGB{255, 255, 255} << std::endl;
    f_out << "[" << _internal::getTime() << "/ERROR] " << message << std::endl;
}

void logger::fatal(const char *message) {
    std::cout << color::RGB{170, 0, 0} << "[" << _internal::getTime() << "/FATAL] " << message << color::RGB{255, 255, 255} << std::endl;
    f_out << "[" << _internal::getTime() << "/FATAL] " << message << std::endl;
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
