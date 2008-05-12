/*
** get_x.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Mon May 12 19:28:13 2008 majdi toumi
** Last update Mon May 12 19:28:25 2008 majdi toumi
*/

#include "server.h"
#include "common.h"

int	get_x(t_client *client, int x_diff, int y_diff)
{
  if (client->direction == EAST)
    return (client->x + y_diff);
  if (client->direction == SOUTH)
    return (client->x - x_diff);
  if (client->direction == WEST)
    return (client->x - y_diff);
  return (client->x + x_diff);
}
