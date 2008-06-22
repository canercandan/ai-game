/*
** get_trame.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 12:10:55 2008 caner candan
** Last update Mon Jun 23 00:25:46 2008 caner candan
*/

#include <string.h>
#include <stdio.h>
#include "observator_2d.h"
#include "common.h"
#include "x.h"

static void	new_item(t_info *info, char **buf)
{
  int		x;
  int		y;
  int		z;

  put_int_from_buf(&x, buf);
  put_int_from_buf(&y, buf);
  put_int_from_buf(&z, buf);
  info->object[x][y][z]++;
}

static void	loop(t_info *info, char **tmp, char *first)
{
  if (!strncmp(first, START_LIST_PLAYER, strlen(START_LIST_PLAYER)))
    create_client(info, tmp);
  else if (!strncmp(first, ADD_CLIENT, strlen(ADD_CLIENT)))
    add_client(info, tmp);
  else if (!strncmp(first, NEW_ITEM, strlen(NEW_ITEM)))
    new_item(info, tmp);
  else if (!strncmp(first, BROADCAST_MESG, strlen(BROADCAST_MESG)))
    {}
  else if (!strncmp(first, TIME, strlen(TIME)))
    put_float_from_buf(&info->time, tmp);
  else if (!strncmp(first, START_LIST_ITEM, strlen(START_LIST_ITEM)))
    get_object(info, tmp);
  else
    if (!info->x || !info->y)
      get_map_size(info, tmp, first);
    else
      execute_action(info, tmp, first);
}

int	get_trame(t_info *info)
{
  int	nbr;
  char	*first;
  char	*tmp;

  if (!(nbr = xrecv(info->socket, info->buf, BUF_SIZE, 0)))
    return (-1);
  info->buf[nbr] = 0;
  tmp = info->buf;
  while ((first = strsep(&tmp, DELIMIT)))
    loop(info, &tmp, first);
  return (0);
}
