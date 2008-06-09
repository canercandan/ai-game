/*
** send_info_to_obs.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May  3 15:19:05 2008 florent hochwelker
** Last update Mon Jun  9 18:41:16 2008 florent hochwelker
*/

#include <string.h>
#include <stdio.h>
#include "server.h"
#include "common.h"

static void	strcat_nb_items_case(t_list *ressources, t_client *client)
{
  int	tab[NOURRITURE + 1];
  int	i;

  bzero(tab, sizeof(tab));
  while (ressources)
    {
      tab[(int)((t_ressource *)ressources->data)->idx]++;
      ressources = ressources->next;
    }
  i = 0;
  while (i < NOURRITURE + 1)
    {
      strcat(client->buf_write, " ");
      putnbr(tab[i], client->buf_write);
      i++;
    }
}

static void	send_map_items(t_client *client, t_info *info)
{
  int		x;
  int		y;

  x = 0;
  strcat(client->buf_write, "LIST_ITEM\n");
  while (x < info->x)
    {
      y = 0;
      while (y < info->y)
	{
	  if (info->zone[x][y].ressources)
	    {
	      putnbr(x, client->buf_write);
	      strcat(client->buf_write, " ");
	      putnbr(y, client->buf_write);
	      strcat_nb_items_case(info->zone[x][y].ressources, client);
	      strcat(client->buf_write, "\n");
	    }
	  y++;
	}
      x++;
    }
  strcat(client->buf_write, "END_LIST_ITEM\n");
}

static void	send_list_players(t_client *obs, t_info *info)
{
  t_list	*clients;

  strcat(obs->buf_write, START_LIST_PLAYER);
  strcat(obs->buf_write, "\n");
  clients = info->clients;
  while (clients)
    {
      if (CLIENT(clients->data)->status == ST_CLIENT ||
	  CLIENT(clients->data)->status == ST_DISCONNECT)
	obs_add_client_in_char(obs->buf_write, clients->data, info,
			       CLIENT(clients->data)->id);
      clients = clients->next;
    }
  strcat(obs->buf_write, END_LIST_PLAYER);
  strcat(obs->buf_write, "\n");
}

void	send_info_to_obs(t_client *client, t_info *info)
{
  snprintf(client->buf_write, BUF_SIZE, "%d %d\n",
	   info->x, info->y);
  send_map_items(client, info);
  send_list_players(client, info);
}
