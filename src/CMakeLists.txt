project(SDLGame)
add_executable(SDLGame main.cpp)
target_link_libraries(SDLGame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS SDLGame RUNTIME DESTINATION ${BIN_DIR})
