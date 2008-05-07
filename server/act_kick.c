/*
** act_kick.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Wed May  7 11:10:49 2008 caner candan
*/

#include "server.h"
#include "common.h"

static int	kick_it(t_client *dst, t_client *src)
{
  (void) dst;
  (void) src;
  return (0);
}

int		act_kick(char *param, t_client *client, t_info *info)
{
  t_list	*clients;
  t_client	*c;
  int		nb_kick;

  (void)param;
  clients = info->zone[client->x][client->y].clients;
  nb_kick = 0;
  while (clients)
    {
      c = clients->data;
      if (c != client)
	if (!kick_it(c, client))
	  nb_kick++;
      clients = clients->next;
    }
  if (nb_kick <= 0)
    {
      send_buf_to_client(client, KO);
      return (-1);
    }
  send_buf_to_client(client, OK);
  return (0);
}
