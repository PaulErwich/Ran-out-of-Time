cmake_minimum_required(VERSION 3.14)
project(SFMLTemplate)

set(CMAKE_CXX_STANDARD 14)


if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h
        src/GameStates/GameStateBase.cpp src/GameStates/GameStateBase.h
        src/GameStates/GameMenu.cpp src/GameStates/GameMenu.h
        src/GameStates/GamePlay.cpp src/GameStates/GamePlay.h
        src/GameStates/GameOver.cpp src/GameStates/GameOver.h
        src/GameStates/GameWin.cpp src/GameStates/GameWin.h
        src/Extra/Helper.cpp src/Extra/Helper.h
        src/GameObjects/GameObject.cpp src/GameObjects/GameObject.h
        src/Extra/Vector2.cpp src/Extra/Vector2.h
        src/GameObjects/Entities/Player.cpp src/GameObjects/Entities/Player.h
        src/GameObjects/Entities/Entity.cpp src/GameObjects/Entities/Entity.h
        src/GameObjects/Entities/Enemy.cpp src/GameObjects/Entities/Enemy.h
        src/GameObjects/Level.cpp src/GameObjects/Level.h
        src/GameObjects/Block.cpp src/GameObjects/Block.h src/Extra/Collisions/CollisionStructs.cpp src/Extra/Collisions/CollisionStructs.h src/Extra/Collisions/CollisionFunctions.cpp src/Extra/Collisions/CollisionFunctions.h src/GameStates/AnimationState.h src/GameObjects/Spring.cpp src/GameObjects/Spring.h src/GameObjects/Cog.cpp src/GameObjects/Cog.h)

add_executable(SFMLTemplate ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (SFMLTemplate sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)
