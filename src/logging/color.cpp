#include "color.h"

std::ostream &color::operator<<(std::ostream &os, const color::RGB &rgb) {
    return os << "\033[38;2;" << (int) rgb.r << ";" << (int) rgb.g << ";" << (int) rgb.b << "m";
}
