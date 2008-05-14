/*
** set_pirate.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 23:05:23 2008 caner candan
** Last update Wed May 14 10:17:12 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"

void		set_pirate(t_gfx *gfx, int nbr, float x, float y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = PIRATE_X * GET_POSITION_X(nbr, PIRATE_MAX_PER_LINE);
  src.y = PIRATE_Y * GET_POSITION_Y(nbr, PIRATE_MAX_PER_LINE);
  src.w = PIRATE_X;
  src.h = PIRATE_Y;
  dst.x = (x + 1) * FLOOR_X;
  dst.y = y * FLOOR_Y;
  dst.w = PIRATE_X;
  dst.h = PIRATE_Y;
  SDL_SetColorKey(gfx->pirate, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->pirate)->format,
			     PIRATE_R, PIRATE_G, PIRATE_B));
  SDL_BlitSurface(gfx->pirate, &src, gfx->video, &dst);
}
