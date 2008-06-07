/*
** get_map_size.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 16:30:12 2008 caner candan
** Last update Sat Jun  7 14:01:10 2008 caner candan
*/

#include <stdio.h>
#include "observator_2d.h"

void	get_map_size(t_info *info, char **buf, char *first)
{
  put_int_from_buf(&(info->x), &first);
  put_int_from_buf(&(info->y), buf);
/*   put_float_from_buf(&(info->time), buf); */
  if (info->x && info->y)
    {
      info->x += 2;
      info->y += 2;
      create_video(info);
    }
}
