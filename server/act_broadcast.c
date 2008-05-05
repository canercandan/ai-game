/*
** act_broadcast.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May  5 21:52:35 2008 caner candan
*/

#include <string.h>
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

static int	give_me_the_k(t_info *info, t_client *dst,
			      t_client *src)
{
  int		diff_x;
  int		diff_y;

  if (ABS(src->x - dst->x) > info->x / 2)
    diff_x = info->x - ABS(src->x - dst->x);
  else
    diff_x = src->x - dst->x;
  if (ABS(src->y - dst->y) > info->y / 2)
    diff_y = info->y - ABS(src->y - dst->y);
  else
    diff_y = src->y - dst->y;
  return (return_res_k(diff_x, diff_y));
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
      c = (t_client *) clients->data;
      if (c != client)
	{
	  send_buf_to_client(c, MESSAGE);
	  snprintf(buf, sizeof(buf), "%d ",
		   give_me_the_k(info, c, client));
	  send_buf_to_client(c, buf);
	  send_buf_to_client(c, param);
	  send_buf_to_client(c, "\n");
	}
      clients = clients->next;
    }
  send_buf_to_client(client, OK);
  return (0);
}
