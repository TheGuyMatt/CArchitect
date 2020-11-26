#ifndef TILESET_H_INCLUDED
#define TILESET_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "texture.h"

//the tileset type
typedef struct
{
  int width, height,
      tile_width, tile_height,
      tiles_col, tiles_row;
  Texture *texture;
} Tileset;

//loads the given tileset
int tileset_load(Tileset* tileset, Texture* texture, int tile_width, int tile_height);

//render tileset at given position and column and row with default width and height
void tileset_render_at_pos(Tileset* tileset, int col, int row, int x, int y);

//render tileset at given position and column and row with given width and height
void tileset_render_at_pos_size(Tileset* tileset, int col, int row, int x, int y, int width, int height);

#endif
