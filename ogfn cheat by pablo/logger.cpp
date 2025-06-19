#include "logger.h"
#include <iostream>

namespace Logger {
    void Log(const std::string& message) {
        std::cout << "[LOG] " << message << std::endl;
    }

    void Error(const std::string& message) {
        std::cerr << "[ERROR] " << message << std::endl;
    }
}
