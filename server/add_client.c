/*
** add_client.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:37:41 2008 caner candan
** Last update Tue Apr 29 21:43:58 2008 caner candan
*/

#include "zappy.h"
#include "server.h"
#include "x.h"

void	add_client(t_env *e, int s)
{
  int	socket;
  t_cli	*c;

  socket = xaccept(s, NULL, NULL);
  client_to_list(e, FD_CLIENT, client_read, NULL);
  c = xmalloc(sizeof(*c));
  c->fd_type = FD_CLIENT;
  c->fct_read = client_read;
  c->fct_write = NULL;
  push_list(&e->clients, (void *) c);
}
