/*
** act_up.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Sat May  3 14:27:00 2008 caner candan
*/

#include <string.h>
#include "server.h"

int		act_up(char *param, t_client *client, t_info *info)
{
  t_list	*list;
  int		x;
  int		y;

  (void) param;
  x = client->x;
  y = client->y;
  list = info->zone[x][y].client;
  rm_client_from_list(&list, client->socket);
  if (client->direction == NORTH)
    client->y = (client->y == 0 ? info->y - 1 : client->y + 1);
  else if (client->direction == EAST)
    client->x = (client->x == (info->x - 1) ? 0 : client->x + 1);
  else if (client->direction == WEST)
    client->x = (client->x == 0 ? info->x - 1 : client->x - 1);
  else
    client->y = (client->y == (info->y - 1) ? 0 : client->y - 1);
  list = info->zone[x][y].client;
  push_list(&list, client->socket);
  info->zone[x][y].client = list;
  strcat(client->buf_write, "UP OK\n");
  return (0);
}
