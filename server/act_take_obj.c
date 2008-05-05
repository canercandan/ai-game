/*
** act_take_obj.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May  5 19:26:48 2008 majdi toumi
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "common.h"

int		act_take_obj(char *param, t_client *client, t_info *info)
{
  t_list	*list;
  t_list	*pos;
  t_ressource	*res;
  int		idx;

  list = info->zone[client->x][client->y].ressources;
  if (!exist_data_from_list(list, param))
    send_buf_to_client(client, KO);
  else
    {
      idx = get_ressource_idx(param);
      if (idx == -1)
	send_buf_to_client(client, KO);
      else
	{
	  pos = list;
	  while (list)
	    {
	      res = (t_ressource *)list->data;
	      if (!strcmp(res->name, param))
		break;
	      list = list->next;
	    }
	  rm_data_from_list(&pos, list->data);
	  client->qte_ressource[idx] += 1;
	  send_buf_to_client(client, OK);
	}
    }
  return (0);
}
