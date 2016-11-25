add_library(common
    utils.cpp
    ltexture.cpp
    lbutton.cpp
)

target_link_libraries(common
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
    Qt5::Core
)