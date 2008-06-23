/*
** act_kick.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon Jun 23 06:04:24 2008 caner candan
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "common.h"

static int	give_me_the_k(t_client *dst, t_client *src)
{
  if ((src->direction == NORTH && dst->direction == SOUTH) ||
      (src->direction == WEST && dst->direction == EAST) ||
      (src->direction == SOUTH && dst->direction == NORTH) ||
      (src->direction == EAST && dst->direction == WEST))
    return (1);
  if ((src->direction == NORTH && dst->direction == WEST) ||
      (src->direction == WEST && dst->direction == SOUTH) ||
      (src->direction == SOUTH && dst->direction == EAST) ||
      (src->direction == EAST && dst->direction == NORTH))
    return (3);
  if (src->direction == dst->direction)
    return (5);
  return (7);
}

static int	kick_it(t_client *dst, t_client *src, t_info *info)
{
  SEND(dst->buf_write, KICKIT);
  putnbr(give_me_the_k(dst, src), dst->buf_write);
  SEND(dst->buf_write, "\n");
  move_up(dst, src->direction, info);
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
	if (!kick_it(c, client, info))
	  nb_kick++;
      clients = clients->next;
    }
  if (nb_kick <= 0)
    {
      SEND(client->buf_write, KO);
      return (-1);
    }
  SEND(client->buf_write, OK);
  return (0);
}
