add_executable(tutorial_002
    main.cpp
)

target_link_libraries(tutorial_002
    ${SDL2_LIBRARIES}
    Qt5::Core
)

add_custom_command(TARGET tutorial_002 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_002/*
    $<TARGET_FILE_DIR:tutorial_002>/
)