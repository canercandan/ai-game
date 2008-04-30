/*
** add_server.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:40:48 2008 caner candan
** Last update Wed Apr 30 14:29:56 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "server.h"
#include "x.h"

void			add_server(t_info *info)
{
  int			s;
  struct sockaddr_in	addr;
  struct protoent	*pe;
  t_cli			*c;

  debug("add_server()");
  pe = getprotobyname("tcp");
  c = xmalloc(sizeof(*c));
  c->socket = xsocket(PF_INET, SOCK_STREAM, pe->p_proto);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(info->port);
  addr.sin_addr.s_addr = INADDR_ANY;
  xbind(s, (struct sockaddr *) &addr, (void *) sizeof(addr));
  xlisten(s, MAX_LISTEN);
  c->fd_type = FD_SERVER;
  c->fct_read = server_read;
  c->fct_write = NULL;
  push_list(&info->clients, (void *) c);
}
