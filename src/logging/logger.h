#ifndef MINECHAD_LOGGER_H
#define MINECHAD_LOGGER_H

#include <ctime>
#include "color.h"

namespace logger {
    enum Level {
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL
    };

    namespace _internal {
        char* getTime();
    };

    void log(Level level, const char* message);
};

#endif //MINECHAD_LOGGER_H
