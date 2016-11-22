add_executable(tutorial_009
    main.cpp
)

target_link_libraries(tutorial_009
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    Qt5::Core
)

add_custom_command(TARGET tutorial_009 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_009/*
    $<TARGET_FILE_DIR:tutorial_009>/
)