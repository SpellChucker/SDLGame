#include "window.h"

Window::Window(const std::string &title, int width, int height) {
  // Create our window.
  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
  this->width = width;
  this->height = height;

  if (window == NULL) {
    printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
  }
}

SDL_Window* Window::getSDLWindow() {
  return window;
}

Window::~Window() {

}
