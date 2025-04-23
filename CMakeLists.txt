cmake_minimum_required(VERSION 3.10)
project(BowlingGame)

set(CMAKE_CXX_STANDARD 17)

# Game source files
set(SOURCES
    main.cpp
    Frame.cpp
    Player.cpp
    BowlingGame.cpp
)

# Header files
set(HEADERS
    Frame.h
    Player.h
    BowlingGame.h
)

add_executable(BowlingGame ${SOURCES} ${HEADERS})

# Tests
add_executable(UnitTests tests.cpp Frame.cpp Player.cpp BowlingGame.cpp)
