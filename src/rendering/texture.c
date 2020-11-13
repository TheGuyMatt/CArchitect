#include "texture.h"
#include "../util/log.h"

int texture_load(Texture *texture, SDL_Renderer *renderer, char filename[])
{
  if (renderer == NULL)
  {
    loge("Bad renderer passed to texture_load");
    return 1;
  }

  texture->renderer_reference = renderer;

  SDL_Surface* tempSurface = IMG_Load(filename);
  if (tempSurface == NULL)
  {
    loge("Unable to load image: %s", filename);
    return 1;
  }

  if ((texture->sdl_texture = SDL_CreateTextureFromSurface(renderer, tempSurface)) == NULL)
  {
    loge("Unable to create texture");
    return 1;
  }

  SDL_QueryTexture(texture->sdl_texture, NULL, NULL, &texture->width, &texture->height);
  SDL_FreeSurface(tempSurface);
  return 0;
}

void texture_render_at_pos(Texture* texture, int x, int y)
{
  texture_render_at_pos_size(texture, x, y, texture->width, texture->height);
}

void texture_render_at_pos_size(Texture* texture, int x, int y, int width, int height)
{
  SDL_Rect destination = {x, y, width, height};
  SDL_RenderCopy(texture->renderer_reference, texture->sdl_texture, NULL, &destination);
}

void texture_render_part(Texture* texture, int x, int y, int width, int height, int sx, int sy, int swidth, int sheight)
{
  SDL_Rect destination = {x, y, width, height};
  SDL_Rect source = {sx, sy, swidth, sheight};
  SDL_RenderCopy(texture->renderer_reference, texture->sdl_texture, &source, &destination);
}
