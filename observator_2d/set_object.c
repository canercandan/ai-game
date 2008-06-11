/*
** set_object.c for zappy in /home/candan_c/rendu/c/zappy/observator_2d
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Jun 11 19:01:30 2008 caner candan
** Last update Wed Jun 11 20:08:07 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"

static t_object	object[] = {
  {"images/floor.bmp", 4, FLOOR_X, FLOOR_Y, 0, 0, 0, 0, 0},
  {"images/status.bmp", 5, 17, 17, -5, -35, 192, 192, 192},
  {"images/object.bmp", 4, 32, 32, 0, 0, 0, 0, 0},
  {"images/bibi.bmp", 4, 32, 48, 0, 0, 255, 255, 255},
  {"images/pirate.bmp", 4, 40,	56, 0, 0, 255, 255, 255},
  {"images/fenix.bmp", 4, 96, 96, -30, -15, 255, 255, 255},
  {NULL, 0, 0, 0, 0, 0, 0, 0, 0}
};

static void	init(t_gfx *gfx, int idx)
{
  if (!gfx->object[idx])
    gfx->object[idx] = load_image(object[idx].path);
}

void		set_object(t_gfx *gfx, t_param *p)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  init(gfx, p->gfx);
  src.x = object[p->gfx].size_x
    * GET_POSITION_X(p->anim, object[p->gfx].max_per_line);
  src.y = object[p->gfx].size_y
    * GET_POSITION_Y(p->anim, object[p->gfx].max_per_line);
  src.w = object[p->gfx].size_x;
  src.h = object[p->gfx].size_y;
  dst.x = p->x + object[p->gfx].padding_x;
  dst.y = p->y + object[p->gfx].padding_y;
  dst.w = object[p->gfx].size_x;
  dst.h = object[p->gfx].size_y;
  SDL_SetColorKey(gfx->object[p->gfx], SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->object[p->gfx])->format,
			     object[p->gfx].r,
			     object[p->gfx].g,
			     object[p->gfx].b));
  SDL_BlitSurface(gfx->object[p->gfx], &src, gfx->video, &dst);
}
