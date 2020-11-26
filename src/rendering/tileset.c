#include "tileset.h"
#include "../util/log.h"

//loads the given tileset
int tileset_load(Tileset* tileset, Texture* texture, int tile_width, int tile_height)
{
  if (tileset == NULL)
  {
    loge("Bad tileset passed to tileset_load");
    return 1;
  }

  if (texture == NULL)
  {
    loge("Bad texture passed to tileset_load");
    return 1;
  }

  tileset->texture = texture;
  tileset->width = texture->width;
  tileset->height = texture->height;
  tileset->tile_width = tile_width;
  tileset->tile_height = tile_height;
  tileset->tiles_col = tileset->width / tileset->tile_width;
  tileset->tiles_row = tileset->height / tileset->tile_height;
}

//render tileset at given position and column and row with default width and height
void tileset_render_at_pos(Tileset* tileset, int col, int row, int x, int y)
{
  texture_render_part(tileset->texture, x, y, tileset->tile_width, tileset->tile_height, col * tileset->tile_width, row * tileset->tile_height, tileset->tile_width, tileset->tile_height);
}

//render tileset at given position and column and row with given width and height
void tileset_render_at_pos_size(Tileset* tileset, int col, int row, int x, int y, int width, int height)
{
  texture_render_part(tileset->texture, x, y, width, height, col * tileset->tile_width, row * tileset->tile_height, tileset->tile_width, tileset->tile_height);
}
