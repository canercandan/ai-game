/*
** set_backdrop.c<2> for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 20:00:33 2008 caner candan
** Last update Wed Jun 11 19:36:52 2008 caner candan
*/

#include "observator_2d.h"

void		set_backdrop(t_info *info)
{
  t_param	p;
  int		x;
  int		y;

  for (y = 0; y < info->y * FLOOR_Y; y += FLOOR_Y)
    for (x = 0; x < info->x * FLOOR_X; x += FLOOR_X)
      {
	p.gfx = FLOOR;
	p.x = x;
	p.y = y;
	if (x < FLOOR_X || y < FLOOR_Y ||
	    x > (info->x * FLOOR_X) - (FLOOR_X * 2) ||
	    y > (info->y * FLOOR_Y) - (FLOOR_Y * 2))
	  p.anim = 0;
	else
	  p.anim = 6;
	set_object(info->gfx, &p);
      }
}
