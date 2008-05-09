/*
** act_drop_obj.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Fri May  9 14:18:33 2008 florent hochwelker
*/

#include <string.h>
#include <sys/time.h>
#include <stdio.h>		/* a vire printf */
#include "server.h"
#include "common.h"

static int		check_if_enough_hp(t_info *info, t_client *client)
{
  struct timeval	tp;

  gettimeofday(&tp, NULL);
  printf("===== check hp =====\n");
  if ((unsigned int)(client->hp - tp.tv_sec - tp.tv_usec / 1e6) /
      (FOOD_HP * info->time) > 0)
    {
      client->hp -= FOOD_HP * info->time;
      send_buf_to_client(client, OK);
      return (1);
    }
  send_buf_to_client(client, KO);
  return (0);
}

int		act_drop_obj(char *param, t_client *client,
			     t_info *info)
{
  t_ressource	*ressource;
  int		idx;

  idx = get_ressource_idx(param);
  if (idx == -1)
    send_buf_to_client(client, KO);
  else if (!strcmp(param, gl_ressource[NOURRITURE].name))
    check_if_enough_hp(info, client);
  else if (client->qte_ressource[idx] > 0)
    {
      client->qte_ressource[idx] -= 1;
      ressource = &gl_ressource[idx];
      push_list(&(info->zone[client->x][client->y].ressources),
		ressource);
      send_buf_to_client(client, OK);
    }
  else
    send_buf_to_client(client, KO);
  return (0);
}
