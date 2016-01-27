#include "entrypoint.hpp"
#include <iostream>

int start(const std::vector<const char*>& args) {
    for (const char* arg : args) {
        std::cout << "Argument: " << arg << std::endl;
    }
    return 0;
}
