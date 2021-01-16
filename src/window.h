#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SDL2/SDL.h>

//the sdl window
extern SDL_Window *sdl_window;

//the sdl renderer, which draws things to the screen
extern SDL_Renderer *sdl_renderer;

//initializes window
int window_create(char title[], int width, int height);

//quits the window and calls destructors
void window_quit();

//clears the window with the given rgba value with the renderer
void window_clear(int r, int g, int b, int a);
//presents everything that needs to be drawn to the window with the renderer
void window_present();

#endif
