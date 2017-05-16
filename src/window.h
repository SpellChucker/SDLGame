#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>

class Window {

  public:
    Window(const std::string &title, int width, int height);

    ~Window();

    SDL_Window* getSDLWindow();
  protected:

  private:
    SDL_Window* window;

    int width;
    int height;
};

#endif
