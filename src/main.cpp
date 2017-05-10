#include <stdio.h>
#include <SDL.h>

/**
 * Where it all begins.
 */
int main(int, char**) {
  SDL_Window* window = NULL;

  SDL_Surface* screenSurface = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) != 0){
    printf("SDL could not be initialized: SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  window = SDL_CreateWindow("First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 728, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  screenSurface = SDL_GetWindowSurface(window);

  // Fill window white.
  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

  SDL_UpdateWindowSurface(window);

  SDL_Delay(2000);

  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}
