add_library(tutorial_012_main
    ltexture.cpp
)

target_link_libraries(tutorial_012_main
    common
)

add_executable(tutorial_012
    main.cpp
)

target_link_libraries(tutorial_012
    tutorial_012_main
    common
)

add_custom_command(TARGET tutorial_012 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_012/*
    $<TARGET_FILE_DIR:tutorial_012>/
)