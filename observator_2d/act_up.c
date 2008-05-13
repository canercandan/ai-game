/*
** act_up.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:05:32 2008 caner candan
** Last update Tue May 13 19:53:18 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

int	act_up(t_info *info, t_client *client, char *param)
{
  (void) param;
  if (client->direction == NORTH)
    client->y = (client->y == 0 ? info->y - 3 : client->y - 1);
  else if (client->direction == EAST)
    client->x = (client->x == (info->x - 1) ? 1 : client->x + 1);
  else if (client->direction == WEST)
    client->x = (client->x == 0 ? info->x - 1 : client->x - 1);
  else
    client->y = (client->y == (info->y - 1) ? 0 : client->y + 1);
  return (0);
}
