/*
** add_client.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:37:41 2008 caner candan
** Last update Tue May 13 23:58:03 2008 florent hochwelker
*/

#include <string.h>
#include "common.h"
#include "server.h"
#include "x.h"

static void	init_ressources(t_client *client)
{
  int		i;

  i = 0;
  while (i < NB_INVENTORY)
    client->qte_ressource[i++] = 0;
}

static void	init_buffer(t_client *client)
{
  client->buf_read[0] = 0;
  client->buf_write[0] = 0;
  client->buf_read[BUF_SIZE] = 0;
  client->buf_write[BUF_SIZE] = 0;
}

t_client	*add_client(t_info *info, int server, int x, int y)
{
  static int	last_x = -1;
  static int	last_y = -1;
  static int	last_direction = -1;
  static int	id = 0;
  t_client	*client;

  client = xmalloc(sizeof(*client));
  client->status = ST_NOT_LOGGED;
  client->fct_read = client_read;
  client->fct_write = client_write;
  init_buffer(client);
  client->level = START_LEVEL;
  client->x = (x ? x : get_random(info->x, last_x));
  client->y = (y ? y : get_random(info->y, last_y));
  last_x = client->x;
  last_y = client->y;
  push_list(&(info->zone[client->x][client->y].clients), client);
  client->direction = get_random(WEST, last_direction);
  client->team = NULL;
  init_ressources(client);
  push_list(&info->clients, (void *)client);
  if (server)
    client->socket = xaccept(server, NULL, NULL);
  client->id = id++;
  return (client);
}
