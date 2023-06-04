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
