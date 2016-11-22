add_executable(tutorial_008
    main.cpp
)

target_link_libraries(tutorial_008
    ${SDL2_LIBRARIES}
    Qt5::Core
)
