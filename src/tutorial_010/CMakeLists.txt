add_library(tutorial_010_main
    ltexture.cpp
)

target_link_libraries(tutorial_010_main
    common
)

add_executable(tutorial_010
    main.cpp
)

target_link_libraries(tutorial_010
    tutorial_010_main
    common
)

add_custom_command(TARGET tutorial_010 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_010/*
    $<TARGET_FILE_DIR:tutorial_010>/
)