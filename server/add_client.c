/*
** add_client.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:37:41 2008 caner candan
** Last update Wed Apr 30 20:11:42 2008 caner candan
*/

#include "server.h"
#include "x.h"

void		add_client(t_info *info, int server)
{
  t_client	*client;

  debug("add_client()", 2);
  client = xmalloc(sizeof(*client));
  client->socket = xaccept(server, NULL, NULL);
  client->fd_type = FD_CLIENT;
  client->fct_read = client_read;
  client->fct_write = client_write;
  push_list(&info->clients, (void *) client);
}
