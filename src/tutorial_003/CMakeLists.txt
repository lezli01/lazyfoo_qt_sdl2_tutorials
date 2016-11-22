add_executable(tutorial_003
    main.cpp
)

target_link_libraries(tutorial_003
    ${SDL2_LIBRARIES}
    Qt5::Core
)

add_custom_command(TARGET tutorial_003 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_003/*
    $<TARGET_FILE_DIR:tutorial_003>/
)