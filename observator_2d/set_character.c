/*
** set_character.c<2> for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 20:02:39 2008 caner candan
** Last update Tue May 13 14:59:22 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"

void		set_character(t_gfx *gfx, int nbr, int x, int y)
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
		  SDL_MapRGB(SDL_SF(gfx->character)->format, 255, 255, 255));
  SDL_BlitSurface(gfx->character, &src, gfx->video, &dst);
}
