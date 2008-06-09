/*
** create_client.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 11:02:18 2008 caner candan
** Last update Mon Jun  9 20:53:22 2008 caner candan
*/

#include <string.h>
#include <stdlib.h>
#include "observator_2d.h"
#include "common.h"
#include "x.h"

static int	loop(t_info *info, char **buf)
{
  int		nbr;

  if (!(*buf)[0])
    {
      if (!(nbr = xrecv(info->socket, info->buf,
			BUF_SIZE, 0)))
	return (-1);
      info->buf[nbr] = 0;
      *buf = info->buf;
    }
  while (!strncmp(*buf, ADD_CLIENT, strlen(ADD_CLIENT)))
    {
      skip_from_buf(buf);
      add_client(info, buf);
    }
  return (0);
}

int	create_client(t_info *info, char **buf)
{
  while (strncmp(*buf, END_LIST_PLAYER, strlen(END_LIST_PLAYER)))
    if (loop(info, buf) < 0)
      return (-1);
  skip_from_buf(buf);
  dump_clients(info);
  return (0);
}
