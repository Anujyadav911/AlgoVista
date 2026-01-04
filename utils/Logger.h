#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

class Logger {
public:
    static void info(const std::string& msg) {
        std::cout << "[INFO] " << msg << std::endl;
    }
};

#endif
