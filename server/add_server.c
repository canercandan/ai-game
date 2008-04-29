/*
** add_server.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:40:48 2008 caner candan
** Last update Tue Apr 29 21:33:43 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "zappy.h"
#include "server.h"
#include "x.h"

void			add_server(t_env *e)
{
  int			s;
  struct sockaddr_in	addr;
  t_cli			*cli;

  debug("add_server()");
  pe = getprotobyname("tcp");
  if ((s = xsocket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    return (-1);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(e->port);
  addr.sin_addr.s_addr = INADDR_ANY;
  xbind(s, (struct sockaddr *) &addr, (void *) sizeof(addr));
  xlisten(s, MAX_LISTEN);
  client_to_list(e, FD_SERVER, server_read, NULL);
  c = xmalloc(sizeof(*s));
  c->fd_type = fd_type;
  c->fct_read = fct_read;
  c->fct_write = fct_write;
  push_list(&e->clients, (void *) c);
}
