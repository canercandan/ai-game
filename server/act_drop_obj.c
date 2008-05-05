/*
** act_drop_obj.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May  5 18:11:44 2008 majdi toumi
*/

#include <string.h>
#include "server.h"
#include "common.h"

int		act_drop_obj(char *param, t_client *client, t_info *info)
{
  int		idx;

  idx = get_ressource_idx(param);
  if (idx == 0)
    send_buf_to_client(client, KO);
  else
    {
      client->qte_ressource[idx] -= 1;
      push_list(&(info->zone[client->x][client->y].ressources), param);
      send_buf_to_client(client, OK);
    }
  return (0);
}
