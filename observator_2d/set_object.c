/*
** set_object.c for zappy in /home/candan_c/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Jun  7 19:44:12 2008 caner candan
** Last update Sun Jun  8 01:50:35 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"

void		set_object(t_gfx *gfx, int nbr, float x, float y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = OBJECT_X * GET_POSITION_X(nbr, OBJECT_MAX_PER_LINE);
  src.y = OBJECT_Y * GET_POSITION_Y(nbr, OBJECT_MAX_PER_LINE);
  src.w = OBJECT_X;
  src.h = OBJECT_Y;
  dst.x = (x + 1) * FLOOR_X;
  dst.y = y * FLOOR_Y;
  dst.w = OBJECT_X;
  dst.h = OBJECT_Y;
  SDL_SetColorKey(gfx->object, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->object)->format,
			     OBJECT_R, OBJECT_G, OBJECT_B));
  SDL_BlitSurface(gfx->object, &src, gfx->video, &dst);
}
