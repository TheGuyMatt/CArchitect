#include "util/log.h"
#include "ecs/ecs.h"
#include "window.h"
#include "rendering/texture.h"
#include "rendering/tileset.h"

#include <SDL_image.h>

int main(int argc, char **argv)
{
  window_create("CArchitect", 1280, 720);

  Texture skytexture;
  texture_load(&skytexture, sdl_renderer, "Resources/Textures/sky.png");
  
  Texture temptileset;
  texture_load(&temptileset, sdl_renderer, "Resources/Textures/TempTileSet.png");
  Tileset realtileset;
  tileset_load(&realtileset, &temptileset, 32, 32);

  window_clear(255, 0, 255, 255);

  texture_render_at_pos_size(&skytexture, 0, 0, 1280, 720);
  tileset_render_at_pos_size(&realtileset, 1, 1, 0, 0, realtileset.tile_width * 10, realtileset.tile_height * 10);

  window_present();

  while (window_closed == 1)
  {
    SDL_Delay(2000);

    window_closed = 0;
  }

  window_quit();

  return 0;
}
