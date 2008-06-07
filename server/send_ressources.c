/*
** send_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Wed May  7 15:24:54 2008 majdi toumi
** Last update Sat Jun  7 17:11:39 2008 majdi toumi
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "common.h"

int		send_ressources(t_info *info, t_client *client, char *buff,
				int *diff)
{
  t_list	*ressources;
  t_list	*players;
  int		x;
  int		y;
  int		i;

  x = get_x(client, diff[0], diff[1]);
  y = get_y(client, diff[0], diff[1]);
  is_in_map(info, &x, &y);
  printf("x: [%d], y: [%d]\n", x, y);
  ressources = info->zone[x][y].ressources;
  players = info->zone[x][y].clients;
  i = 0;
  while (players)
    {
      if (diff[0] != 0 || diff[1] != 0 || i != 0)
	strcat(buff, SEPARATOR_ELM);
      strncat(buff, "joueur");
      players = players->next;
      i++;
    }
  i = 0;
  if (info->zone[x][y].clients)
    strcat(buff, " ");
  while (ressources)
    {
      if (diff[0] != 0 || diff[1] != 0 || i != 0)
	strcat(buff, SEPARATOR_ELM);
      strcat(buff, ((t_ressource *)ressources->data)->name);
      ressources = ressources->next;
      i++;
    }
  return (0);
}

