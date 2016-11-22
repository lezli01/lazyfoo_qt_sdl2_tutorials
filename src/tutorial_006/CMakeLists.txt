add_executable(tutorial_006
    main.cpp
)

target_link_libraries(tutorial_006
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    Qt5::Core
)

add_custom_command(TARGET tutorial_006 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_006/*
    $<TARGET_FILE_DIR:tutorial_006>/
)