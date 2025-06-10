file(GLOB SOURCES
    src/*.cpp
)

include_directories(headers)

add_executable(game ${SOURCES})

target_link_libraries(game PRIVATE raylib GL m pthread dl rt X11)
