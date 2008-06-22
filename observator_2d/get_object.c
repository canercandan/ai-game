/*
** get_object.c for zappy in /home/candan_c/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat Jun  7 14:02:20 2008 caner candan
** Last update Mon Jun 23 00:25:32 2008 caner candan
*/

#include <string.h>
#include <stdlib.h>
#include "observator_2d.h"
#include "common.h"
#include "x.h"

static int	loop(t_info *info, char **buf)
{
  int		x;
  int		y;
  int		nbr;

  if (!(*buf)[0])
    {
      if (!(nbr = xrecv(info->socket, info->buf,
			BUF_SIZE, 0)))
	return (-1);
      info->buf[nbr] = 0;
      *buf = info->buf;
    }
  put_int_from_buf(&x, buf);
  put_int_from_buf(&y, buf);
  put_int_from_buf(&info->object[x][y][0], buf);
  put_int_from_buf(&info->object[x][y][1], buf);
  put_int_from_buf(&info->object[x][y][2], buf);
  put_int_from_buf(&info->object[x][y][3], buf);
  put_int_from_buf(&info->object[x][y][4], buf);
  put_int_from_buf(&info->object[x][y][5], buf);
  put_int_from_buf(&info->object[x][y][6], buf);
  put_int_from_buf(&info->object[x][y][7], buf);
  return (0);
}

int	get_object(t_info *info, char **buf)
{
  if (!buf[0])
    return (-1);
  while (strncmp(*buf, END_LIST_ITEM, strlen(END_LIST_ITEM)))
    if (loop(info, buf) < 0)
      return (-1);
  skip_from_buf(buf);
  return (0);
}
