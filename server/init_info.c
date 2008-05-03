/*
** init_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 15:01:08 2008 caner candan
** Last update Sat May  3 14:57:03 2008 caner candan
*/

#include <sys/time.h>
#include "server.h"
#include "x.h"

t_info			*init_info()
{
  struct timeval	*timeout;
  t_info		*info;

  info = xmalloc(sizeof(*info));
  info->queue = 0;
  timeout = xmalloc(sizeof(*timeout));
  timeout->tv_sec = 0;
  timeout->tv_usec = 0;
  info->timeout = timeout;
  info->observator = NULL;
  return (info);
}
