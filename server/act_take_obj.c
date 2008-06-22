/*
** act_take_obj.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon Jun 23 00:59:22 2008 caner candan
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "common.h"

static int	if_exist(char *param, t_client *client, t_info *info)
{
  t_list	*list;
  int		idx;  

  list = info->zone[client->x][client->y].ressources;
  idx = get_ressource_idx(param);
  if (idx == -1)
    {
      SEND(client->buf_write, KO);
      return (-1);
    }
  else
    {
      if (!strcmp(param, gl_ressource[NB_INVENTORY - 1].name))
	client->hp += FOOD_HP * info->time;
      else
	client->qte_ressource[idx] += 1;
      rm_ressource_from_list(&list, param);
      info->zone[client->x][client->y].ressources = list;
      SEND(client->buf_write, OK);
    }
  return (0);
}

int		act_take_obj(char *param, t_client *client, t_info *info)
{
  if (!exist_data_from_list(info->zone[client->x][client->y].ressources,
			    param))
    {
      SEND(client->buf_write, KO);
      return (-1);
    }
  else
    if (if_exist(param, client, info) < 0)
      return (-1);
  return (0);
}
