/*
** set_backdrop.c<2> for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 20:00:33 2008 caner candan
** Last update Tue May 13 19:46:20 2008 caner candan
*/

#include "observator_2d.h"

void	set_backdrop(t_info *info, t_gfx *gfx)
{
  int	x;
  int	y;

  for (y = 0; y < info->y * FLOOR_Y; y += FLOOR_Y)
    for (x = 0; x < info->x * FLOOR_X; x += FLOOR_X)
      {
	if (x < FLOOR_X ||
	    y < FLOOR_Y ||
	    x > (info->x * FLOOR_X) - (FLOOR_X * 2) ||
	    y > (info->y * FLOOR_Y) - (FLOOR_Y * 2))
	  set_floor(gfx, 0, x, y);
	else
	  set_floor(gfx, 6, x, y);
      }
}
