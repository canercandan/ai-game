/*
** add_server.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:40:48 2008 caner candan
** Last update Tue Apr 22 18:37:04 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "x.h"
#include "server.h"
#include "zappy.h"

void	add_server(t_env *e)
{
  int			s;
  struct sockaddr_in	sin;

  s = xsocket(PF_INET, SOCK_STREAM, 0);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  xbind(s, (struct sockaddr *) &sin, (void *) sizeof(sin));
  xlisten(s, 42);
  e->fd_type[s] = FD_SERVER;
  e->fct_read[s] = server_read;
  e->fct_write[s] = NULL;
}
