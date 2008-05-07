/*
** act_kick.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Wed May  7 13:59:50 2008 caner candan
*/

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
  move_up(dst, src->direction, info);
  send_buf_to_client(dst, KICKIT);
  putnbr(give_me_the_k(dst, src), dst->buf_write);
  send_buf_to_client(dst, "\n");
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
      send_buf_to_client(client, KO);
      return (-1);
    }
  send_buf_to_client(client, OK);
  return (0);
}
