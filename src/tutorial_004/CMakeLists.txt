add_executable(tutorial_004
    main.cpp
)

target_link_libraries(tutorial_004
    ${SDL2_LIBRARIES}
    Qt5::Core
)

add_custom_command(TARGET tutorial_004 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_004/*
    $<TARGET_FILE_DIR:tutorial_004>/
)