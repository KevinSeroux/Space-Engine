cmake_minimum_required(VERSION 2.6)

project(GameEngine)
set(LIBRARY_OUTPUT_PATH lib)

include_directories(
	${sdl_include_dir}
	${gl3_include_dir}
)
link_directories(${sdl_lib_dir})

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

target_link_libraries(
	GameEngine
	${sdl_lib_name}
)
	
