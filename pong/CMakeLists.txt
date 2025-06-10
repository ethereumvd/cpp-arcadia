include_directories(.)

add_executable(pong
    main.cpp
)

target_link_libraries(pong PRIVATE raylib GL m pthread dl rt X11)
