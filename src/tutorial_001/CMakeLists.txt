add_executable(tutorial_001
    main.cpp
)

target_link_libraries(tutorial_001
    ${SDL2_LIBRARIES}
    Qt5::Core
)
