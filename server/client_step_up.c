/*
** client_setp_up.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/include
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Wed Apr 30 15:04:19 2008 majdi toumi
** Last update Sat May  3 13:06:41 2008 majdi toumi
*/

#include "server.h"

char		*client_step_up(t_zone **world, t_info *info, t_client *client)
{
  t_list	*list;
  int		x;
  int		y;

  x = client->x;
  y = client->y;
  list = world[x][y].client;
  pop_in_list(&list, client->socket);
  if (client->direction == NORTH)
    client->y = (client->y == 0 ? info->width - 1 : client->y + 1);
  else if (client->direction == EAST)
    client->x = (client->x == (info->lenght - 1) ? 0 : client->x + 1);
  else if (client->direction == WEST)
    client->x = (client->x == 0 ? info->lenght - 1 : client->x - 1);
  else
    client->y = (client->y == (info->width - 1) ? 0 : client->y - 1);
  list = world[x][y].client;
  push_in_list(&list, client->socket);
  world[x][y].client = list;
  return ("ok");
}

