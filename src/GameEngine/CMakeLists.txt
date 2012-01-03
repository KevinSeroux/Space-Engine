set(LIBRARY_OUTPUT_PATH ../../lib)

file(
	GLOB_RECURSE
	source_files
	*
)

add_library(
	GameEngine
	STATIC
	${source_files}
)

target_link_libraries(
	GameEngine
	/usr/local/lib/SDL
)

include_directories(
	/usr/local/include/GL3
	/usr/local/include/SDL
)
