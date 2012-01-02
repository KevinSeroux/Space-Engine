cmake_minimum_required(VERSION 2.6)

project(Game)
set(EXECUTABLE_OUTPUT_PATH ../../bin/${CMAKE_BUILD_TYPE})

include_directories(../../include)
link_directories(../../lib)

#Configuration de l'exécutable
file(
	GLOB_RECURSE
	source_files
	*
)
add_executable(
	Game
	${source_files}
)

target_link_libraries(
	Game
	GameEngine
)
