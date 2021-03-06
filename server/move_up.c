/*
** move_up.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May  7 11:07:13 2008 caner candan
** Last update Tue May 13 21:07:28 2008 majdi
*/

#include "server.h"
#include "common.h"

int	move_up(t_client *client, char direction, t_info *info)
{
  rm_data_from_list(&(info->zone[client->x][client->y].clients), client);
  if (direction == NORTH)
    client->y = (client->y == 0 ? info->y - 1 : client->y - 1);
  else if (direction == EAST)
    client->x = (client->x == (info->x - 1) ? 0 : client->x + 1);
  else if (direction == WEST)
    client->x = (client->x == 0 ? info->x - 1 : client->x - 1);
  else
    client->y = (client->y == (info->y - 1) ? 0 : client->y + 1);
  push_list(&(info->zone[client->x][client->y].clients), client);
  return (0);
}
