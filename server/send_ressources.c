/*
** send_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Wed May  7 15:24:54 2008 majdi toumi
** Last update Mon May 12 13:07:57 2008 majdi toumi
*/

#include <stdio.h>
#include <string.h>
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

int		send_ressources(t_info *info, t_client *client, char *buff,
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
  i = 0;
  while (ressources)
    {
      if (x_diff != 0 || y_diff != 0 || i != 0)
	strcat(buff, SEPARATOR_ELM);
      strcat(buff, ((t_ressource *) ressources->data)->name);
      ressources = ressources->next;
      i++;
    }
  return (0);
}

int		send_len_ressources(t_info *info, t_client *client,
				int x_diff, int y_diff)
{
  t_list	*ressources;
  int		len;
  int		x;
  int		y;
  int		i;

  len = 0;
  x = get_x(client, x_diff, y_diff);
  y = get_y(client, x_diff, y_diff);
  is_in_map(info, &x, &y);
  ressources = info->zone[x][y].ressources;
  i = 0;
  while (ressources)
    {
      if (x_diff != 0 || y_diff != 0 || i != 0)
	len += strlen(SEPARATOR_ELM);
      len += strlen(((t_ressource *) ressources->data)->name);
      ressources = ressources->next;
      i++;
    }
  return (len);
}
