/*
** send_info_to_obs.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May  3 15:19:05 2008 florent hochwelker
** Last update Wed Jun  4 17:54:07 2008 caner candan
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

static void	send_list_players(t_client *obs, t_info *info)
{
  t_list	*clients;

  clients = info->clients;
  while (clients)
    {
      if (CLIENT(clients->data)->status == ST_CLIENT ||
	  CLIENT(clients->data)->status == ST_DISCONNECT)
	obs_add_client_in_char(obs->buf_write, clients->data, info,
			       CLIENT(clients->data)->id);
      clients = clients->next;
    }
}

void	send_info_to_obs(t_client *client, t_info *info)
{
  snprintf(client->buf_write, BUF_SIZE, "%d %d %f\n",
	   info->x, info->y, info->time);
  send_list_players(client, info);
}
