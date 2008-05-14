/*
** set_character.c<2> for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 20:02:39 2008 caner candan
** Last update Wed May 14 10:17:19 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"

void		set_character(t_gfx *gfx, int nbr, float x, float y)
{
  SDL_Rect	src;
  SDL_Rect	dst;

  src.x = CHARACTER_X * GET_POSITION_X(nbr, CHARACTER_MAX_PER_LINE);
  src.y = CHARACTER_Y * GET_POSITION_Y(nbr, CHARACTER_MAX_PER_LINE);
  src.w = CHARACTER_X;
  src.h = CHARACTER_Y;
  dst.x = (x + 1) * FLOOR_X;
  dst.y = y * FLOOR_Y;
  dst.w = CHARACTER_X;
  dst.h = CHARACTER_Y;
  SDL_SetColorKey(gfx->character, SDL_SRCCOLORKEY,
		  SDL_MapRGB(SDL_SF(gfx->character)->format,
			     CHARACTER_R, CHARACTER_G, CHARACTER_B));
  SDL_BlitSurface(gfx->character, &src, gfx->video, &dst);
}
