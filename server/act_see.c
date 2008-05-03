/*
** act_see.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Sat May  3 20:30:43 2008 caner candan
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

static int	is_in_map(t_info *info, int x, int y)
{
  if (x >= info->x || x < 0)
    return (-1);
  if (y >= info->y || y < 0)
    return (-1);
  return (0);
}

static int	get_x(t_client *client, int x_diff, int y_diff)
{
  if (client->direction == EAST)
    return (client->x + y_diff);
  if (client->direction == SOUTH)
    return (client->x - x_diff);
  if (client->direction == WEST)
    return (client->x - y_diff);
  return (client->x + x_diff);
}

static int	get_y(t_client *client, int x_diff, int y_diff)
{
  if (client->direction == EAST)
    return (client->y + x_diff);
  if (client->direction == SOUTH)
    return (client->y - y_diff);
  if (client->direction == WEST)
    return (client->y - x_diff);
  return (client->y + y_diff);
}

static int	send_ressources(t_info *info, t_client *client,
				int x_diff, int y_diff)
{
  t_list	*ressources;
  int		x;
  int		y;

  x = get_x(client, x_diff, y_diff);
  y = get_y(client, x_diff, y_diff);
  if (is_in_map(info, x, y) < 0)
    return (-1);
  ressources = info->zone[x][y].ressources;
  while (ressources)
    {
      strcat(client->buf_write, SEPARATOR_ELM);
      strcat(client->buf_write, ((t_ressource *) ressources->data)->name);
      ressources = ressources->next;
    }
  strcat(client->buf_write, SEPARATOR_CMD);
  return (0);
}

int	act_see(char *param, t_client *client, t_info *info)
{
  int	i;
  int	j;

  (void) param;
  strcat(client->buf_write, START_CMD);
  send_ressources(info, client, 0, 0);
  for (i = 0; i <= client->level; i++)
    for (j = 0 - i; j <= 0 + i; j++)
      {
	printf("i: [%d], j: [%d]\n", i, j);
	send_ressources(info, client, j, i);
      }
  strcat(client->buf_write, END_CMD);
  return (0);
}
