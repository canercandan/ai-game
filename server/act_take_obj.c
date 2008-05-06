/*
** act_take_obj.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Tue May  6 17:17:14 2008 majdi toumi
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "common.h"

/*
static void	*get_param_from_list(t_list *list, char *param)
{
  t_ressource	*res;

  while (list)
    {
      res = (t_ressource *)list->data;
      if (!strcmp(res->name, param))
	return (list->data);
      list = list->next;
    }
  return ((void *) -1);
}
*/

int		act_take_obj(char *param, t_client *client, t_info *info)
{
  t_list	*list;
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
	  printf("BEFORE\n");
	  dump_ressources(list);
	  rm_ressource_from_list(&list, param);
	  printf("AFTER\n");
	  dump_ressources(list);
	  info->zone[client->x][client->y].ressources = list;
	  client->qte_ressource[idx] += 1;
	  send_buf_to_client(client, OK);
	}
    }
  return (0);
}
