/*
** send_info_to_obs.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May  3 15:19:05 2008 florent hochwelker
<<<<<<< .mine
** Last update Mon Jun 23 01:48:04 2008 caner candan
=======
** Last update Thu Jun 19 23:04:04 2008 florent hochwelker
>>>>>>> .r569
*/

#include <string.h>
#include <stdio.h>
#include "server.h"
#include "common.h"

static void	strcat_nb_items_case(t_list *ressources, t_client *client)
{
  int		tab[NOURRITURE + 1];
  int		i;

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

  for (x = 0; x < info->x; x++)
    for (y = 0; y < info->y; y++)
      {
	if (info->zone[x][y].ressources)
	  {
	    putnbr(x, client->buf_write);
	    strcat(client->buf_write, " ");
	    putnbr(y, client->buf_write);
	    strcat_nb_items_case(info->zone[x][y].ressources, client);
	    strcat(client->buf_write, " ");
	    putnbr(info->zone[x][y].nb_egg, client->buf_write);
	    strcat(client->buf_write, "\n");
	    client_write(info, client);
	  }
      }
}

static void	send_map(t_client *client, t_info *info)
{
  strcat(client->buf_write, START_LIST_ITEM);
  strcat(client->buf_write, "\n");
  send_map_items(client, info);
  strcat(client->buf_write, END_LIST_ITEM);
  strcat(client->buf_write, "\n");
  client_write(info, client);
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
	{
	  obs_add_client_in_char(obs->buf_write, clients->data, info, 0);
	  client_write(info, obs);
	}
      clients = clients->next;
    }
  strcat(obs->buf_write, END_LIST_PLAYER);
  strcat(obs->buf_write, "\n");
  client_write(info, obs);
}

void	send_info_to_obs(t_client *client, t_info *info)
{
  snprintf(client->buf_write, BUF_SIZE, "%d %d\n",
	   info->x, info->y);
  client_write(info, client);
  send_map(client, info);
  send_list_players(client, info);
  sprintf(client->buf_write, "%s%s %f\n",
	  client->buf_write, TIME, 1.0 / info->time);
  client_write(info, client);
}
