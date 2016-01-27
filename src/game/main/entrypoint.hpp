#ifndef DERELECT_GAME_ENTRYPOINT_H
#define DERELECT_GAME_ENTRYPOINT_H

#include <vector>

/**
 * The actual entry point into the application
 * @param args The arguments to the application
 * @return the return code
 */
int start(const std::vector<const char*>& args);


#endif // DERELECT_GAME_ENTRYPOINT_H
