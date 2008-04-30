/*
** server_init.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 10:15:36 2008 caner candan
** Last update Tue Apr 29 19:20:43 2008 caner candan
*/

#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "zappy.h"
#include "server.h"

void	server_init(t_env *e, char *port)
{
  memset(e->fd_type, FD_FREE, MAX_FD);
  e->port = atoi(port);
  add_server(e);
  ((struct timeval *) (e->timeout))->tv_sec = 5;
  ((struct timeval *) (e->timeout))->tv_usec = 0;
}