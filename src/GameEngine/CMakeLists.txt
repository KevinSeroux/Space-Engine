set(LIBRARY_OUTPUT_PATH lib)

file(
	GLOB_RECURSE
	sources_files
	*
)

add_library(
	GameEngine
	STATIC
	${sources_files}
)

include_directories(../../include)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}../../lib)

target_link_libraries(
	GameEngine
	SDL
)
