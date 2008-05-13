/*
** loop_env.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:40:02 2008 caner candan
** Last update Tue May 13 19:47:07 2008 caner candan
*/

#include <SDL.h>
#include <sys/select.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "observator_2d.h"
#include "common.h"
#include "x.h"

static int	get_direction(t_client *client)
{
  if (client->direction == NORTH)
    return (12);
  if (client->direction == EAST)
    return (8);
  if (client->direction == SOUTH)
    return (0);
  return (4);
}

static void	put_clients(t_info *info, t_gfx *gfx)
{
  t_list	*t;

  t = info->clients;
  while (t)
    {
      set_character(gfx, get_direction(t->data),
		    CLIENT(t->data)->x, CLIENT(t->data)->y);
      t = t->next;
    }
}

static int	put_gfx(t_info *info, t_gfx *gfx)
{
  if (!info->x || !info->y)
    return (-1);
  set_backdrop(info, gfx);
  put_clients(info, gfx);
  SDL_Flip(gfx->video);
  SDL_Delay(DELAY);
  return (0);
}

int			loop_env(t_info *info, t_gfx *gfx)
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
    get_trame(info, gfx);
  put_gfx(info, gfx);
  return (0);
}
