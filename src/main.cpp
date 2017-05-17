#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "window.h"

std::string getResourcePath(const std::string &subDir = "") {
#ifdef _WIN32
  const char PATH_SEP = '\\';
#else
  const char PATH_SEP = '/';
#endif
  static std::string baseRes;
  if (baseRes.empty()){
    char *basePath = SDL_GetBasePath();
    if (basePath){
      baseRes = basePath;
      SDL_free(basePath);
    }
    else {
      printf("Error getting resource path: %s\n", SDL_GetError());
      return "";
    }
    //We replace the last bin/ with res/ to get the the resource path
    size_t pos = baseRes.rfind("bin");
    baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
  }
  return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
}

/**
 * Load a texture given a file name and a renderer.
 *
 * @param file The image file to load
 * @param renderer The renderer to load the texture onto
 * @return The loaded texture or nullptr if error
 */
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer* renderer) {
  SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());

  if (texture == NULL) {
    printf("Could not load image. SDL_Error: %s\n", SDL_GetError());
  }

  return texture;
}

/**
 * Render the texture to a renderer with a specific width, height, x, and y.
 *
 * @param texture The source texture we want to draw
 * @param renderer The renderer we want to draw the texture to
 * @param x The X coordinate to draw to
 * @param y The Y coordinate to draw to
 * @param width The width of the image we want to draw
 * @param height The height of the image we want to draw
 */
void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int width, int height) {
  SDL_Rect destination;
  destination.x = x;
  destination.y = y;
  destination.w = width;
  destination.h = height;
  SDL_RenderCopy(renderer, texture, NULL, &destination);
}

/**
 * Render the texture to a renderer to a specific location preserving the width/height.
 *
 * @param texture The source texture we want to draw
 * @param renderer The renderer we want to draw the texture to
 * @param x The X coordinate to draw to
 * @param y The Y coordinate to draw to
 */
void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {
  int width, height;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  renderTexture(texture, renderer, x, y, width, height);
}

/**
 * Where it all begins.
 */
int main(int, char**) {
  // Initialize SDL's video.
  if (SDL_Init(SDL_INIT_VIDEO) != 0){
    printf("SDL could not be initialized. SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  Window* windowObject = new Window("First Window", 1024, 728);

  SDL_Window* window = windowObject->getSDLWindow();

  // Create our renderer.
  SDL_Renderer* renderer = windowObject->getRenderer();

  std::string imageFile = getResourcePath() + "pete_penguin.png";
  SDL_Texture *loadedTexture = loadTexture(imageFile, renderer);

  if (loadedTexture == NULL) {
    printf("Unable to load texture. SDL_Error: %s\n", SDL_GetError());
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  SDL_Event event;
  bool quit = false;

  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }

    SDL_RenderClear(renderer);
    renderTexture(loadedTexture, renderer, 352, 164);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(loadedTexture);

  SDL_DestroyRenderer(renderer);

  SDL_DestroyWindow(window);

  IMG_Quit();

  SDL_Quit();

  return 0;
}
