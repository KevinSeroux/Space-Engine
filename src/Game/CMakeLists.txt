set(EXECUTABLE_OUTPUT_PATH ../../bin)

file(
	GLOB_RECURSE
	source_files
	*
)
	
add_executable(
	Game
	${source_files}
)

link_directories(../../lib)

target_link_libraries(
	Game
	GameEngine
)
