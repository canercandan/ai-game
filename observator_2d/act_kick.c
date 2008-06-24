/*
** act_kick.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:20:59 2008 caner candan
** Last update Tue Jun 24 13:57:37 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

static int	kick_it(t_client *dst, t_client *src, t_info *info)
{
  move_up(dst, src->direction, info);
  return (0);
}

int	act_kick(t_info *info, t_client *client, char *param)
{
  t_list	*clients;
  t_client	*c;
  int		nb_kick;

  (void)param;
  if (!client)
    return (-1);
  clients = info->clients;
  nb_kick = 0;
  while (clients)
    {
      c = clients->data;
      if (c != client &&
	  c->x == client->x &&
	  c->y == client->y)
	if (!kick_it(c, client, info))
	  nb_kick++;
      clients = clients->next;
    }
  if (nb_kick <= 0)
    return (-1);
  return (0);
}
