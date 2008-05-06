/*
** act_see.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Tue May  6 17:32:17 2008 caner candan
*/

#include <stdio.h>
#include "server.h"
#include "common.h"

static void	is_in_map(t_info *info, int *x, int *y)
{
  if (*x < 0)
    *x = info->x - ABS(*x % info->x);
  if (*y < 0)
    *y = info->y - ABS(*y % info->x);
  *x %= info->x;
  *y %= info->y;
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
    return (client->y + y_diff);
  if (client->direction == WEST)
    return (client->y - x_diff);
  return (client->y - y_diff);
}

static int	send_ressources(t_info *info, t_client *client,
				int x_diff, int y_diff)
{
  t_list	*ressources;
  int		x;
  int		y;
  int		i;

  x = get_x(client, x_diff, y_diff);
  y = get_y(client, x_diff, y_diff);
  is_in_map(info, &x, &y);
  printf("x: [%d], y: [%d]\n", x, y);
  ressources = info->zone[x][y].ressources;
  for (i = 0; ressources; i++)
    {
      if (x_diff != 0 || y_diff != 0 || i != 0)
	send_buf_to_client(client, SEPARATOR_ELM);
      send_buf_to_client(client, ((t_ressource *) ressources->data)->name);
      ressources = ressources->next;
    }
  return (0);
}

int	act_see(char *param, t_client *client, t_info *info)
{
  int	i;
  int	j;

  (void) param;
  send_buf_to_client(client, START_CMD);
  for (i = 0; i <= client->level; i++)
    for (j = 0 - i; j <= i; j++)
      {
	send_ressources(info, client, j, i);
	if (i != client->level || j != i)
	  send_buf_to_client(client, SEPARATOR_CMD);
      }
  send_buf_to_client(client, END_CMD);
  return (0);
}
