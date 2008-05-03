/*
** add_client.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:37:41 2008 caner candan
** Last update Sat May  3 17:28:04 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "x.h"

t_client	*add_client(t_info *info, int server)
{
  t_client	*client;

  debug("add_client()", 2);
  client = xmalloc(sizeof(*client));
  client->socket = xaccept(server, NULL, NULL);
  client->status = ST_NOT_LOGGED;
  client->fct_read = client_read;
  client->fct_write = client_write;
  client->buf_read[0] = 0;
  client->buf_write[0] = 0;
  client->x = get_random(info->x);
  client->y = get_random(info->y);
  push_list(&info->clients, (void *)client);
  return (client);
}
