#include "util/log.h"
#include "ecs/ecs.h"
#include "window.h"

int main(int argc, char **argv)
{
  window_create("CArchitect", 800, 600);

  window_clear(255, 0, 255, 255);
  window_present();

  while (window_closed == 1)
  {
    SDL_Delay(2000);

    window_closed = 0;
  }

  return 0;
}
