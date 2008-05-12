/*
** set_backdrop.c<2> for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 20:00:33 2008 caner candan
** Last update Mon May 12 21:08:00 2008 caner candan
*/

#include "observator_2d.h"

void	set_backdrop(t_gfx *gfx)
{
  int	x;
  int	y;

  for (y = 0; y < gfx->y * FLOOR_Y; y += FLOOR_Y)
    for (x = 0; x < gfx->x * FLOOR_X; x += FLOOR_X)
      {
	if (x < FLOOR_X ||
	    y < FLOOR_Y ||
	    x > (gfx->x * FLOOR_X) - (FLOOR_X * 2) ||
	    y > (gfx->y * FLOOR_Y) - (FLOOR_Y * 2))
	  set_floor(gfx, 0, x, y);
	else
	  set_floor(gfx, 2, x, y);
      }
}
