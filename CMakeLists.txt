cmake_minimum_required(VERSION 3.14)
project(SFMLTemplate)

set(CMAKE_CXX_STANDARD 14)


if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES Project/src/main.cpp Project/src/Game.cpp Project/src/Game.h)
add_executable(SFMLTemplate ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (SFMLTemplate sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY Project/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data/)
