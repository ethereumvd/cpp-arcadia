cmake_minimum_required(VERSION 3.15)
project(AllGames)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure all executables go into build/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories (each has its own CMakeLists.txt)
add_subdirectory(conways-game-of-life)
add_subdirectory(pong)
add_subdirectory(snake)
add_subdirectory(tetris)
