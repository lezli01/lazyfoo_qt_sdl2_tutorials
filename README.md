LazyFoo SDL2 tutorials with Qt5 and CMake
=========================================

Following this guide: http://lazyfoo.net/tutorials/SDL/

This project aims to follow the above tutorials mixing up
with CMake and Qt5 where applicable.

Notes
-----
Change **CMakeModules/qt.cmake** to point your installation of Qt5.

    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} <YOUR QT5 PATH>)

Building and Running Lessons
----------------------------
**Linux GCC**

1. Issue cmake pointing to the root of the repository

    `cmake <repository root>`
    
2. Make _all_ or desired lesson (_tutorial_XXX_)

    `make all`
    `make tutorial_001`
    `...`

3. Run desired binary under _\<your build directory\>/src/tutorial_XXX/_

    `./src/tutorial_001/tutorial_001`
    `...`
