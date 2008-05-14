/*
** loop_env.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:40:02 2008 caner candan
** Last update Wed May 14 10:41:40 2008 caner candan
*/

#include <sys/select.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "observator_2d.h"

int			loop_env(t_info *info)
{
  fd_set		fd_read;
  int			fd_max;
  struct timeval	tp;

  if (catch_keys() < 0)
    return (-1);
  FD_ZERO(&fd_read);
  fd_max = info->socket;
  FD_SET(info->socket, &fd_read);
  tp.tv_sec = 0;
  tp.tv_usec = 100000;
  if (select(fd_max + 1, &fd_read, NULL, NULL, &tp) < 0)
    {
      perror("select");
      exit(-1);
    }
  if (FD_ISSET(info->socket, &fd_read))
    if (get_trame(info))
      return (-1);
  draw_gfx(info, 0);
  return (0);
}
