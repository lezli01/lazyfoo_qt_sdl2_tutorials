add_executable(tutorial_015
    main.cpp
)

target_link_libraries(tutorial_015
    common
)

add_custom_command(TARGET tutorial_015 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_015/*
    $<TARGET_FILE_DIR:tutorial_015>/
)