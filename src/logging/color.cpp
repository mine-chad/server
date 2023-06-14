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

#include "color.h"

std::ostream &color::operator<<(std::ostream &os, const color::RGB &rgb) {
    return os << "\033[38;2;" << (int) rgb.r << ";" << (int) rgb.g << ";" << (int) rgb.b << "m";
}
