#include "util/log.h"
#include "ecs/ecs.h"
#include "window.h"
#include "rendering/texture.h"
#include "rendering/tileset.h"

#include <SDL2/SDL_timer.h>
#include <SDL_image.h>

int game_running = 0;
#define FPS 60
#define FTT (1000 / FPS)
int last_frame_time = 0;

Texture skytexture;
Texture pinetreetexture;
Texture temptileset;
Tileset realtileset;

float groundx = 0;

void setup()
{
  //loads window, inits game_running boolean
  game_running = window_create("CArchitect", 1280, 720);

  //texture loading is temporarily put here
  texture_load(&skytexture, sdl_renderer, "Resources/Textures/sky.png");

  texture_load(&pinetreetexture, sdl_renderer, "Resources/Textures/PineTree.png");
  
  texture_load(&temptileset, sdl_renderer, "Resources/Textures/TempTileSet.png");
  tileset_load(&realtileset, &temptileset, 32, 32);
}

//processes input
void process_input()
{
  SDL_Event evnt;
  SDL_PollEvent(&evnt);

  switch (evnt.type)
  {
    case SDL_QUIT:
      game_running = 0;
      break;

    case SDL_KEYDOWN:
      switch (evnt.key.keysym.sym)
      {
        case SDLK_ESCAPE:
          game_running = 0;
          break;
      }
      break;
  }
}

//updates the game
void update()
{
  int time_to_wait = FTT - (SDL_GetTicks() - last_frame_time);
  if (time_to_wait > 0 && time_to_wait <= FTT) SDL_Delay(time_to_wait);

  float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

  last_frame_time = SDL_GetTicks();

  groundx += 1280 * delta_time;
}

//renders to the screen
void draw()
{
  window_clear(255, 0, 255, 255);

  texture_render_at_pos_size(&skytexture, 0, 0, 1280, 720);

  /*for (int i = 0; i < 7; i++) texture_render_at_pos_size(&pinetreetexture, i * 2 * pinetreetexture.width, 720 - pinetreetexture.height * 3, pinetreetexture.width * 2, pinetreetexture.height * 2);*/
  
  for (int i = 0; i < 1280 / 64; i++)
  {
    tileset_render_at_pos_size(&realtileset, 1, 0, i * 64 + (int)groundx, 720 - 64 * 3, 64, 64);
    tileset_render_at_pos_size(&realtileset, 0, 1, i * 64 + (int)groundx, 720 - 64 * 2, 64, 64);
    tileset_render_at_pos_size(&realtileset, 0, 1, i * 64 + (int)groundx, 720 - 64, 64, 64);
  }

  window_present();
}

int main(int argc, char **argv)
{
  setup();

  while (game_running)
  {
    process_input();
    update();
    draw();
  }

  window_quit();

  return 0;
}
