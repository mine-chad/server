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

#ifndef MINECHAD_COLOR_H
#define MINECHAD_COLOR_H

#include <iostream>

namespace color {
    struct RGB {
        unsigned char r, g, b;
    };

    std::ostream& operator<<(std::ostream& os, const RGB& rgb);
};

#endif //MINECHAD_COLOR_H
