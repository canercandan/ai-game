/*
** act_left.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Sat May  3 14:26:30 2008 caner candan
*/

#include <string.h>
#include "server.h"

int	act_left(char *param, t_client *client, t_info *info)
{
  (void) param;
  (void) info;
  if (client->direction == NORTH)
    client->direction = WEST;
  else if (client->direction == WEST)
    client->direction = SOUTH;
  else if (client->direction == SOUTH)
    client->direction = EAST;
  else if (client->direction == EAST)
    client->direction = NORTH;
  strcat(client->buf_write, "LEFT OK\n");
  return (0);
}
