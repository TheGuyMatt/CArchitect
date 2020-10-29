#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "log.h"

SDL_Window *sdl_window = NULL;
SDL_Renderer *sdl_renderer = NULL;
int window_closed = 0;

int window_create(char title[], int width, int height)
{
  //initialize SDL_Video
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    loge("Failed to initialize SDL_Video");
    return 1;
  }

  //create the window
  sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  if (sdl_window == NULL)
  {
    loge("Failed to create window");
    return 1;
  }

  //create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (sdl_renderer == NULL)
  {
    loge("Failed to create renderer");
    return 1;
  }

  window_closed = 1;

  return 0;
}

void window_quit()
{
  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void window_clear(int r, int g, int b, int a)
{
  SDL_SetRenderDrawColor(sdl_renderer, r, g, b, a);
  SDL_RenderClear(sdl_renderer);
}

void window_present()
{
  SDL_RenderPresent(sdl_renderer);
}
