/*
** act_up.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Sun May  4 16:02:37 2008 caner candan
*/

#include <string.h>
#include "common.h"
#include "server.h"

int		act_up(char *param, t_client *client, t_info *info)
{
  t_list	*list;

  (void) param;
  list = info->zone[client->x][client->y].client;
  rm_client_from_list(&list, client);
  if (client->direction == NORTH)
    client->y = (client->y == 0 ? info->y - 1 : client->y - 1);
  else if (client->direction == EAST)
    client->x = (client->x == (info->x - 1) ? 0 : client->x + 1);
  else if (client->direction == WEST)
    client->x = (client->x == 0 ? info->x - 1 : client->x - 1);
  else
    client->y = (client->y == (info->y - 1) ? 0 : client->y + 1);
  list = info->zone[client->x][client->y].client;
  push_list(&list, client);
  info->zone[client->x][client->y].client = list;
  strcat(client->buf_write, OK);
  return (0);
}
