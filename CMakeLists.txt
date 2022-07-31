cmake_minimum_required(VERSION 3.14)
project(SFMLTemplate)

set(CMAKE_CXX_STANDARD 14)


if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/GameStates/GameStateBase.cpp src/GameStates/GameStateBase.h src/GameStates/GameMenu.cpp src/GameStates/GameMenu.h src/GameStates/GamePlay.cpp src/GameStates/GamePlay.h src/GameStates/GameOver.cpp src/GameStates/GameOver.h src/GameStates/GameWin.cpp src/GameStates/GameWin.h src/Extra/Helper.cpp src/Extra/Helper.h)
add_executable(SFMLTemplate ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (SFMLTemplate sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)
