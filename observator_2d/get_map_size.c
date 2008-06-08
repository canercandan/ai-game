/*
** get_map_size.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 16:30:12 2008 caner candan
** Last update Sun Jun  8 05:05:58 2008 caner candan
*/

#include <stdlib.h>
#include "observator_2d.h"
#include "x.h"

static void	alloc_object(t_info *info)
{
  int	x;
  int	y;
  int	z;

  info->object = malloc(sizeof(*(info->object))
			* info->x);
  for (x = 0; x < info->x; x++)
    {
      info->object[x] = malloc(sizeof(**(info->object))
			       * info->y);
      for (y = 0; y < info->y; y++)
	for (z = 0; z < NB_OBJECT; z++)
	  info->object[x][y][z] = 0;
    }
}

static void	alloc_broadcast(t_info *info)
{
  int	x;
  int	y;

  info->broadcast = malloc(sizeof(*(info->broadcast))
			   * info->x);
  for (x = 0; x < info->x; x++)
    {
      info->broadcast[x] = malloc(sizeof(**(info->broadcast))
				  * info->y);
      for (y = 0; y < info->y; y++)
	info->broadcast[x][y] = 0;
    }
}

void	get_map_size(t_info *info, char **buf, char *first)
{
  put_int_from_buf(&(info->x), &first);
  put_int_from_buf(&(info->y), buf);
  if (info->x && info->y)
    {
      alloc_object(info);
      alloc_broadcast(info);
      info->x += 2;
      info->y += 2;
      create_video(info);
    }
}
