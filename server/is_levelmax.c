/*
** is_levelmax.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 17:31:24 2008 caner candan
** Last update Mon May 12 18:32:39 2008 caner candan
*/

#include "server.h"

int		is_levelmax(t_client *client, t_info *info)
{
  t_list	*t;

  t = info->zone[client->x][client->y].clients;
  while (t)
    {
      if (CLIENT(t->data)->level == MAX_LEVEL)
	if (count_list_with_same_team_n_lvl(info->clients,
					    CLIENT(t->data)->team,
					    CLIENT(t->data)->level) ==
	    CLIENT(t->data)->team->nb)
	  return (0);
      t = t->next;
    }
  return (-1);
}
