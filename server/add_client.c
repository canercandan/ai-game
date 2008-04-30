/*
** add_client.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:37:41 2008 caner candan
** Last update Wed Apr 30 14:29:16 2008 caner candan
*/

#include "server.h"
#include "x.h"

void	add_client(t_info *info, int server)
{
  t_cli	*c;

  debug("add_client()");
  c = xmalloc(sizeof(*c));
  c->socket = xaccept(server, NULL, NULL);
  c->fd_type = FD_CLIENT;
  c->fct_read = client_read;
  c->fct_write = NULL;
  push_list(&info->clients, (void *) c);
}
