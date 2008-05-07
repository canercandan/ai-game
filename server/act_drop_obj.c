/*
** act_drop_obj.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Wed May  7 11:12:12 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "common.h"

int		act_drop_obj(char *param, t_client *client,
			     t_info *info)
{
  t_ressource	*ressource;
  int		idx;

  idx = get_ressource_idx(param);
  if (idx == -1)
    send_buf_to_client(client, KO);
  else
    {
      if (client->qte_ressource[idx] > 0)
	{
	  if (!strcmp(param, gl_ressource[NB_INVENTORY - 1].name))
	    client->hp -= FOOD_HP;
	  else
	    client->qte_ressource[idx] -= 1;
	  ressource = &gl_ressource[idx];
	  push_list(&(info->zone[client->x][client->y].ressources),
		    ressource);
	  send_buf_to_client(client, OK);
	}
      else
	send_buf_to_client(client, KO);
    }
  return (0);
}
