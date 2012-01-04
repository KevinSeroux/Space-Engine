cmake_minimum_required(VERSION 2.6)

project(GameEngine)

include_directories(include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

find_package(OpenGL 3 REQUIRED)
find_package(SDL 1.3 REQUIRED)

add_subdirectory(src/GameEngine)
add_subdirectory(src/Game)
