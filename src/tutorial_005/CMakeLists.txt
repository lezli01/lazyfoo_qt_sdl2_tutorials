add_executable(tutorial_005
    main.cpp
)

target_link_libraries(tutorial_005
    ${SDL2_LIBRARIES}
    Qt5::Core
)

add_custom_command(TARGET tutorial_005 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/assets/tutorial_005/*
    $<TARGET_FILE_DIR:tutorial_005>/
)