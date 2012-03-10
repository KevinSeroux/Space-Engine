set(LIBRARY_OUTPUT_PATH ../../lib)

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

include_directories(/usr/local/include)

link_directories(
	/usr/local/lib
	/usr/lib
)

target_link_libraries(
	GameEngine
	SDL2
	GL
)
