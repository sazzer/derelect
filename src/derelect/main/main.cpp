#include <entrypoint.hpp>

int main(const int argc, const char** argv) {
    std::vector<const char*> args(argv, argv + argc);
    
    return start(args);
}
