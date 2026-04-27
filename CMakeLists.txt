cmake_minimum_required(VERSION 3.10)

project(GuessInt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(game
    main.cpp
    Game.cpp
    Player.cpp
    Utils.cpp
    ComputerGuesser.cpp
)

# Debug flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")

# Release flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Sanitizers (optional build type)
set(CMAKE_CXX_FLAGS_SANITIZE
    "-g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer"
)