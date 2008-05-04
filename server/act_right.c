/*
** act_right.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Sun May  4 13:40:19 2008 caner candan
*/

#include <string.h>
#include "server.h"

int	act_right(char *param, t_client *client, t_info *info)
{
  (void) param;
  (void) info;
  if (client->direction == NORTH)
    client->direction = EAST;
  else if (client->direction == EAST)
    client->direction = SOUTH;
  else if (client->direction == SOUTH)
    client->direction = WEST;
  else if (client->direction == WEST)
    client->direction = NORTH;
  strcat(client->buf_write, MESG_RET);
  return (0);
}
