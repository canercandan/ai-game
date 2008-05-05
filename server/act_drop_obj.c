/*
** act_drop_obj.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May  5 19:13:39 2008 majdi toumi
*/

#include <string.h>
#include "server.h"
#include "common.h"

int		act_drop_obj(char *param, t_client *client, t_info *info)
{
  t_list	*list;
  int		idx;

  idx = get_ressource_idx(param);
  if (idx == -1)
    send_buf_to_client(client, KO);
  else
    {
      list = info->zone[client->x][client->y].ressources;
      push_list(&list, param);
      client->qte_ressource[idx] -= 1;
      send_buf_to_client(client, OK);
    }
  return (0);
}
