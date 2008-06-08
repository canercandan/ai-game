/*
** get_object.c for zappy in /home/candan_c/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Jun  7 14:02:20 2008 caner candan
** Last update Sun Jun  8 01:44:12 2008 caner candan
*/

#include <string.h>
#include <stdlib.h>
#include "observator_2d.h"
#include "common.h"

int	get_object(t_info *info, char **buf)
{
  char	*str;
  int	x;
  int	y;

  if (strncmp(*buf, START_LIST, strlen(START_LIST)))
    return (-1);
  put_char_from_buf(&str, buf);
  free(str);
  while (strncmp(*buf, END_LIST, strlen(END_LIST)))
    {
      put_int_from_buf(&x, buf);
      put_int_from_buf(&y, buf);
      put_int_from_buf(&info->object[x][y][0], buf);
      put_int_from_buf(&info->object[x][y][1], buf);
      put_int_from_buf(&info->object[x][y][2], buf);
      put_int_from_buf(&info->object[x][y][3], buf);
      put_int_from_buf(&info->object[x][y][4], buf);
      put_int_from_buf(&info->object[x][y][5], buf);
    }
  put_char_from_buf(&str, buf);
  free(str);
  return (0);
}
