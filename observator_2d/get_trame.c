/*
** get_trame.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 12:10:55 2008 caner candan
** Last update Tue May 13 20:12:48 2008 caner candan
*/

#include <string.h>
#include <stdio.h>
#include "observator_2d.h"
#include "x.h"

int	get_trame(t_info *info, t_gfx *gfx)
{
  int	nbr;
  char	*first;
  char	*tmp;

  if (!(nbr = xrecv(info->socket, info->buf, BUF_SIZE, 0)))
    return (-1);
  info->buf[nbr] = 0;
  printf("buf: [%s]\n", info->buf);
  tmp = info->buf;
  while ((first = strsep(&tmp, DELIMIT)))
    {
      printf("first: [%s]\n", first);
      if (!strncmp(ADD_CLIENT, first, strlen(ADD_CLIENT)))
	create_client(info, &tmp);
      else
	if (!info->x || !info->y)
	  get_map_size(info, gfx, &tmp, first);
	else
	  execute_action(info, &tmp, first);
    }
  return (0);
}