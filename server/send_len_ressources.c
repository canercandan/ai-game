/*
** send_len_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Mon May 12 19:23:02 2008 majdi toumi
** Last update Tue Jun 24 12:24:35 2008 majdi toumi
*/

#include <string.h>
#include "server.h"
#include "common.h"

static int	len_players(t_list *players, int x_diff, int y_diff, int *i)
{
  t_client	*clt;
  int		len;

  while (players)
    {
      clt = players->data;
      if (clt->status == ST_CLIENT || clt->status == ST_DISCONNECT)
	{
	  if (x_diff != 0 || y_diff != 0 || *i != 0)
	    len += strlen(SEPARATOR_ELM);
	  len += strlen("joueur");
	}
      players = players->next;
      (*i)++;
    }
  return (len);
}

int		send_len_ressources(t_info *info, t_client *client,
				    int x_diff, int y_diff)
{
  t_list	*ressources;
  t_list	*players;
  int		len;
  int		x;
  int		y;
  int		i;

  i = 0;
  x = get_x(client, x_diff, y_diff);
  y = get_y(client, x_diff, y_diff);
  is_in_map(info, &x, &y);
  ressources = info->zone[x][y].ressources;
  players = info->zone[x][y].clients;
  len = len_players(players, x_diff, y_diff, &i);
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
