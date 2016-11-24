add_executable(tutorial_014
    main.cpp
)

target_link_libraries(tutorial_014
    common
)

add_custom_command(TARGET tutorial_014 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_014/*
    $<TARGET_FILE_DIR:tutorial_014>/
)