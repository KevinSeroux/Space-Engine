cmake_minimum_required(VERSION 2.6)

project(GameEngine)
set(LIBRARY_OUTPUT_PATH lib)
set(CMAKE_CXX_FLAGS, "`sdl-config --cflags`")

include_directories(
	/usr/local/include/GL3
)

file(
	GLOB_RECURSE
	source_files
	src/GameEngine/*
	include/*
)

add_library(
	GameEngine
	STATIC
	${source_files}
)

link_libraries(
	GameEngine
	GL3
)
	
