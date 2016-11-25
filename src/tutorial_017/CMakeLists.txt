add_executable(tutorial_017
    main.cpp
)

target_link_libraries(tutorial_017
    common
)

add_custom_command(TARGET tutorial_017 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_017/*
    $<TARGET_FILE_DIR:tutorial_017>/
)