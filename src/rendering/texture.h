#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL_image.h>

//the texture type that will be used to store and render textures
typedef struct
{
  int width, height;
  SDL_Renderer* renderer_reference;
  SDL_Texture* sdl_texture;
} Texture;

//loads the given texture using sdl to be rendered
int texture_load(Texture* texture, SDL_Renderer* renderer, char filename[]);

//render texture at given position and default width and height
void texture_render_at_pos(Texture* texture, int x, int y);

//render texture at given position and a width and height
void texture_render_at_pos_size(Texture* texture, int x, int y, int width, int height);

//render texture at given position, a width and height, and a part of the texture
void texture_render_part(Texture* texture, int x, int y, int width, int height, int sx, int sy, int swidth, int sheight);

#endif
