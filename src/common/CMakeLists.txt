add_library(common
    utils.cpp
)

target_link_libraries(common
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    Qt5::Core
)