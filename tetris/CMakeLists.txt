file(GLOB SOURCES
    src/*.cpp
)

include_directories(headers)

add_executable(tetris ${SOURCES})

target_link_libraries(tetris PRIVATE raylib GL m pthread dl rt X11)
