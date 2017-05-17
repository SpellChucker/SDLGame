#include "window.h"

Window::Window(const std::string &title, int width, int height) {
  this->width   = width;
  this->height  = height;

  // Create our window.
  SDL_CreateWindowAndRenderer(
      this->width,
      this->height,
      SDL_WINDOW_SHOWN,
      &this->window,
      &this->renderer);

  if (this->window == NULL) {
    printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
  }

  if (this->renderer== NULL) {
    SDL_DestroyWindow(this->window);
    printf("Render could not be created. SDL_Error: %s\n", SDL_GetError());
  }

  this->setTitle(title);
}

void Window::setTitle(const std::string &title) {
  SDL_SetWindowTitle(this->window, title.c_str());
}

SDL_Window* Window::getSDLWindow() {
  return this->window;
}

SDL_Renderer* Window::getRenderer() {
  return this->renderer;
}

Window::~Window() {

}
