add_library(tutorial_013_main
    ltexture.cpp
)

target_link_libraries(tutorial_013_main
    common
)

add_executable(tutorial_013
    main.cpp
)

target_link_libraries(tutorial_013
    tutorial_013_main
    common
)

add_custom_command(TARGET tutorial_013 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_013/*
    $<TARGET_FILE_DIR:tutorial_013>/
)