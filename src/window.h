#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>

class Window {

  public:
    Window(const std::string &title, int width, int height);

    ~Window();

    SDL_Window* getSDLWindow();

    SDL_Renderer* getRenderer();
  protected:

  private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    void setTitle(const std::string &title);

    int width;
    int height;
};

#endif
