project(SDLGame)
add_executable(SDLGame main.cpp)
target_link_libraries(SDLGame ${SDL2_LIBRARY})
install(TARGETS SDLGame RUNTIME DESTINATION ${BIN_DIR})
