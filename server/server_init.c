/*
** server_init.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 10:15:36 2008 caner candan
** Last update Wed Apr 30 16:02:12 2008 caner candan
*/

#include <sys/time.h>
#include "server.h"
#include "x.h"

void			server_init(t_info *info)
{
  struct timeval	*timeout;

  debug("server_init()", 1);
  timeout = xmalloc(sizeof(*timeout));
  add_server(info);
  timeout->tv_sec = 5;
  timeout->tv_usec = 0;
  info->timeout = timeout;
}
