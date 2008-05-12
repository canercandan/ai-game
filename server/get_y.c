/*
** get_y.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Mon May 12 19:28:44 2008 majdi toumi
** Last update Mon May 12 19:30:21 2008 majdi toumi
*/

#include "server.h"
#include "common.h"

int	get_y(t_client *client, int x_diff, int y_diff)
{
  if (client->direction == EAST)
    return (client->y + x_diff);
  if (client->direction == SOUTH)
    return (client->y + y_diff);
  if (client->direction == WEST)
    return (client->y - x_diff);
  return (client->y - y_diff);
}

