project(SDLGame)
add_executable(SDLGame main.cpp window.cpp)
target_link_libraries(SDLGame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
install(TARGETS SDLGame RUNTIME DESTINATION ${BIN_DIR})
