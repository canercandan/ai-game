/*
** send_info_to_obs.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May  3 15:19:05 2008 florent hochwelker
** Last update Sat Jun  7 12:02:47 2008 florent hochwelker
*/

#include <string.h>
#include <stdio.h>
#include "server.h"
#include "common.h"

static void	send_map_items(t_client *client, t_info *info)
{
  t_list	*ressources;
  int		x;
  int		y;

  x = 0;
  strcat(client->buf_write, "LIST ITEM\n");
  while (x < info->x)
    {
      y = 0;
      while (y < info->y)
	{
	  ressources = info->zone[x][y].ressources;
	  if (ressources)
	    {
	      strcat(client->buf_write, "[");
	      putnbr(x, client->buf_write);
	      strcat(client->buf_write, "]");
	      strcat(client->buf_write, "[");
	      putnbr(y, client->buf_write);
	      strcat(client->buf_write, "]");
	      strcat(client->buf_write, " ");
	      while (ressources)
		{
		  putnbr(((t_ressource *)ressources->data)->idx, client->buf_write);
		  if (ressources->next)
		    strcat(client->buf_write, SEPARATOR_ELM);
		  ressources = ressources->next;
		}
	      strcat(client->buf_write, "\n");
	    }
	  y++;
	}
      x++;
    }
  strcat(client->buf_write, "END LIST ITEM\n");
}

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
  snprintf(client->buf_write, BUF_SIZE, "%d %d\n",
	   info->x, info->y);
  send_map_items(client, info);
  send_list_players(client, info);
}
