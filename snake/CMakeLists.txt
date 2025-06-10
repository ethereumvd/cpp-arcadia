include_directories(.)

add_executable(snake
    main.cpp
)

target_link_libraries(snake PRIVATE raylib GL m pthread dl rt X11)
