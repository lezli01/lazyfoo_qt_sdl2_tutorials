add_executable(tutorial_016
    main.cpp
)

target_link_libraries(tutorial_016
    common
)

add_custom_command(TARGET tutorial_016 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_016/*
    $<TARGET_FILE_DIR:tutorial_016>/
)