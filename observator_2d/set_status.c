/*
** set_status.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 20:03:20 2008 caner candan
** Last update Wed May 14 10:17:25 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"

void		set_status(t_gfx *gfx, int nbr, float x, float y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = STATUS_X * GET_POSITION_X(nbr, STATUS_MAX_PER_LINE);
  src.y = STATUS_Y * GET_POSITION_Y(nbr, STATUS_MAX_PER_LINE);
  src.w = STATUS_X;
  src.h = STATUS_Y;
  dst.x = (x * FLOOR_X) - 5;
  dst.y = (y * FLOOR_Y) - 10;
  dst.w = STATUS_X;
  dst.h = STATUS_Y;
  SDL_SetColorKey(gfx->status, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->status)->format,
			     STATUS_R, STATUS_G, STATUS_B));
  SDL_BlitSurface(gfx->status, &src, gfx->video, &dst);
}
