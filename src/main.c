#include "util/log.h"
#include "ecs/ecs.h"
#include "window.h"
#include "rendering/texture.h"

#include <SDL_image.h>

int main(int argc, char **argv)
{
  window_create("CArchitect", 800, 600);

  Texture skytexture;
  texture_load(&skytexture, sdl_renderer, "Resources/Textures/sky.png");

  window_clear(255, 0, 255, 255);

  texture_render_at_pos_size(&skytexture, 0, 0, 800, 600);

  window_present();

  while (window_closed == 1)
  {
    SDL_Delay(2000);

    window_closed = 0;
  }

  window_quit();

  return 0;
}
