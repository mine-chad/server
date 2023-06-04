#include <iostream>
#include "logging/logger.h"

int main() {
    logger::log(logger::INFO, "Hello, world!");
    return 0;
}
