#include "logger.h"

void logger::log(logger::Level level, const char *message) {
    switch(level) {
        case DEBUG:
            std::cout << color::RGB{0, 255, 255} << "[" << _internal::getTime() << "/DEBUG] " << message << color::RGB{255, 255, 255} << std::endl;
            break;
        case INFO:
            std::cout << color::RGB{0, 255, 0} << "[" << _internal::getTime() << "/INFO] " << message << color::RGB{255, 255, 255} << std::endl;
            break;
        case WARN:
            std::cout << color::RGB{255, 255, 0} << "[" << _internal::getTime() << "/WARN] " << message << color::RGB{255, 255, 255} << std::endl;
            break;
        case ERROR:
            std::cout << color::RGB{255, 85, 85} << "[" << _internal::getTime() << "/ERROR] " << message << color::RGB{255, 255, 255} << std::endl;
            break;
        case FATAL:
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
