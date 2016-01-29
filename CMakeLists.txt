CMAKE_MINIMUM_REQUIRED(VERSION 3.4)
PROJECT(Derelect LANGUAGES CXX)

INCLUDE(CTest)

SET(CMAKE_CXX_STANDARD 14)
ADD_DEFINITIONS(-Wall -Wextra -pedantic -Wshadow -Werror)

ADD_LIBRARY(game
    src/game/main/ecs/entityId.cpp
    src/game/main/entrypoint.cpp)
ADD_EXECUTABLE(game_test
    external/bandit/specs/main.cpp
    src/game/test/ecs/entityId_test.cpp)
TARGET_LINK_LIBRARIES(game_test PRIVATE game)
TARGET_INCLUDE_DIRECTORIES(game_test PRIVATE src/game/main)
TARGET_INCLUDE_DIRECTORIES(game_test PRIVATE external/bandit)
ADD_TEST(game game_test)
    
ADD_EXECUTABLE(derelect 
    src/derelect/main/main.cpp)
TARGET_LINK_LIBRARIES(derelect PRIVATE game)
TARGET_INCLUDE_DIRECTORIES(derelect PRIVATE src/game/main)
