/*
** act_left.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May  5 08:28:07 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "common.h"

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
  send_buf_to_client(client, OK);
  return (0);
}
