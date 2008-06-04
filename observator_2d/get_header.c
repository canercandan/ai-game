/*
** get_header.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:46:52 2008 caner candan
** Last update Wed Jun  4 17:50:22 2008 caner candan
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "observator_2d.h"
#include "common.h"
#include "x.h"

static int	recv_welcome(t_info *info)
{
  int	nbr;

  info->buf[0] = 0;
  if ((nbr = xrecv(info->socket, info->buf, BUF_SIZE, 0)) > 0)
    {
      info->buf[nbr] = 0;
      if (strncmp(MSG_WELCOME, info->buf, strlen(MSG_WELCOME)))
	return (-1);
    }
  return (0);
}

static int	send_magic(t_info *info)
{
  xsend(info->socket, MAGIC_OBS, strlen(MAGIC_OBS), 0);
  xsend(info->socket, "\n", 1, 0);
  return (0);
}

int	get_header(t_info *info)
{
  if (recv_welcome(info) < 0)
    return (-1);
  if (send_magic(info) < 0)
    return (-1);
  return (0);
}
