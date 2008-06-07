/*
** act_left.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:19:17 2008 caner candan
** Last update Sat Jun  7 11:21:32 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

int	act_left(t_info *info, t_client *client, char *param)
{
  (void) info;
  (void) param;
  if (!client)
    return (-1);
  if (client->direction == NORTH)
    client->direction = WEST;
  else if (client->direction == WEST)
    client->direction = SOUTH;
  else if (client->direction == SOUTH)
    client->direction = EAST;
  else if (client->direction == EAST)
    client->direction = NORTH;
  return (0);
}
