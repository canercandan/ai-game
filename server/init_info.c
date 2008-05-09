/*
** init_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 15:01:08 2008 caner candan
** Last update Fri May  9 02:04:22 2008 florent hochwelker
*/

#include <sys/time.h>
#include "server.h"
#include "x.h"

t_info			*init_info()
{
  struct timeval	*timeout;
  t_info		*info;

  info = xmalloc(sizeof(*info));
  timeout = xmalloc(sizeof(*timeout));
  timeout->tv_sec = -1;
  timeout->tv_usec = -1;
  info->timeout = timeout;
  info->observator = NULL;
  info->queue = NULL;
  info->clients = NULL;
  info->team = NULL;
  return (info);
}
