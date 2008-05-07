/*
** move_up.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May  7 11:07:13 2008 caner candan
** Last update Wed May  7 11:28:22 2008 caner candan
*/

#include "server.h"
#include "common.h"

int		move_up(t_client *client, int direction, t_info *info)
{
  t_list	*list;

  list = info->zone[client->x][client->y].clients;
  rm_data_from_list(&list, client);
  if (direction == NORTH)
    client->y = (client->y == 0 ? info->y - 1 : client->y - 1);
  else if (direction == EAST)
    client->x = (client->x == (info->x - 1) ? 0 : client->x + 1);
  else if (direction == WEST)
    client->x = (client->x == 0 ? info->x - 1 : client->x - 1);
  else
    client->y = (client->y == (info->y - 1) ? 0 : client->y + 1);
  list = info->zone[client->x][client->y].clients;
  push_list(&list, client);
  info->zone[client->x][client->y].clients = list;
  return (0);
}
