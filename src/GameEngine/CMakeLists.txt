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
if(OPENGL_FOUND)
	message("Success to find OpenGL 3 :")
	message("Include directory : ${OPENGL_INCLUDE_DIR}")
	include_directories(${OPENGL_INCLUDE_DIR})
	message("Link library : ${OPENGL_LIBRARIES}")
	target_link_libraries(GameEngine ${OPENGL_LIBRARIES})
else()
	message("Failed to find OpenGL 3")
endif()

if(SDL_FOUND)
	message("Success to find SDL-1.3 :")
	message("Include directory : ${SDL_INCLUDE_DIR}")
	include_directories(${SDL_INCLUDE_DIR})
	message("Link library : ${SDL_LIBRARY}")
	target_link_libraries(GameEngine ${SDL_LIBRARY})
else()
	message("Failed to find SDL-1.3")
endif()
