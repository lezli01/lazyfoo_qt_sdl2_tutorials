add_library(tutorial_011_main
    ltexture.cpp
)

target_link_libraries(tutorial_011_main
    common
)

add_executable(tutorial_011
    main.cpp
)

target_link_libraries(tutorial_011
    tutorial_011_main
    common
)

add_custom_command(TARGET tutorial_011 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_011/*
    $<TARGET_FILE_DIR:tutorial_011>/
)