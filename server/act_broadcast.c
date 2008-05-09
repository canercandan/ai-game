/*
** act_broadcast.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Fri May  9 18:33:14 2008 florent hochwelker
*/

#include <stdio.h>
#include "server.h"
#include "common.h"

static int	return_res_k(int diff_x, int diff_y)
{
  if (diff_x == 0 && diff_y > 0)
    return (1);
  if (diff_x > 0 && diff_y > 0)
    return (2);
  if (diff_x > 0 && diff_y == 0)
    return (3);
  if (diff_x > 0 && diff_y < 0)
    return (4);
  if (diff_x == 0 && diff_y < 0)
    return (5);
  if (diff_x < 0 && diff_y < 0)
    return (6);
  if (diff_x < 0 && diff_y == 0)
    return (7);
  if (diff_x < 0 && diff_y > 0)
    return (8);
  return (0);
}

static int	with_direction(int val, t_client *client)
{
  int		add;

  if (client->direction == NORTH)
    add = 0;
  else if (client->direction == WEST)
    add = 2;
  else if (client->direction == SOUTH)
    add = 4;
  else
    add = 6;
  val += add;
  val %= 8;
  if (val == 0)
    return (8);
  return (val);
}

static int	give_me_the_k(t_client *dst, t_client *src,
			      t_info *info)
{
  int		diff_x;
  int		diff_y;
  int		res;

  if ((!(src->x - dst->x) && !(src->y - dst->y) &&
       (square_root(power(ABS(src->x - dst->x), 2) +
		    power(ABS(src->y - dst->y), 2)) >
	square_root(power(info->x, 2) - power(info->y, 2)) / 2)) ||
      (!(src->x - dst->x) && ABS(src->y - dst->y) > info->y / 2) ||
      (!(src->y - dst->y) && ABS(src->x - dst->x) > info->x / 2))
    {
      diff_x = info->x - ABS(src->x - dst->x);
      diff_y = info->y - ABS(src->y - dst->y);
      return (return_res_k(diff_x, diff_y));
    }
  diff_x = dst->x - src->x;
  diff_y = dst->y - src->y;
  res = return_res_k(diff_x, diff_y);
  return (with_direction(res, dst));
}

int		act_broadcast(char *param, t_client *client,
			      t_info *info)
{
  t_list	*clients;
  t_client	*c;
  char		buf[5];

  clients = info->clients;
  while (clients)
    {
      c = (t_client *)clients->data;
      if (c != client)
	{
	  send_buf_to_client(c, MESSAGE);
	  snprintf(buf, sizeof(buf), "%d ",
		   give_me_the_k(c, client, info));
	  send_buf_to_client(c, buf);
	  send_buf_to_client(c, param);
	  send_buf_to_client(c, "\n");
	}
      clients = clients->next;
    }
  send_buf_to_client(client, OK);
  return (0);
}
