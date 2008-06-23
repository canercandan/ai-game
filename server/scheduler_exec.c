/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Mon Jun 23 01:43:13 2008 caner candan
*/

#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "common.h"
#include "server.h"

static int	execme(t_info *info, t_queue *elem)
{
  int		ret;

  if ((ret = elem->f(elem->param, elem->client, info)) == LOOP_FOR_SEND)
    return (-1);
  if (elem->idx_f == BIRD)
    obs_send_action(elem->client->id, info, elem->idx_f, "");
  else if (elem->idx_f == LEVELUP && ret < 0)
    obs_send_action(elem->client->id, info, elem->idx_f, "0");
  else if (elem->idx_f == LEVELUP && ret >= 0)
    obs_send_action(elem->client->id, info, elem->idx_f, "1");
  else if (ret >= 0)
    obs_send_action(elem->client->id, info, elem->idx_f, elem->param);
  dump_client_position(info->clients);
  info->queue = info->queue->next;
  free(elem->param);
  free(elem->time);
  free(elem);
  return (0);
}

int			scheduler_exec(t_info *info, void *tp)
{
  t_queue		*elem;

  while (info->queue && (elem = info->queue->data) &&
	 ((TIMEVAL(elem->time)->tv_sec < TIMEVAL(tp)->tv_sec) ||
	  ((TIMEVAL(elem->time)->tv_sec == TIMEVAL(tp)->tv_sec) &&
	   TIMEVAL(elem->time)->tv_usec <= TIMEVAL(tp)->tv_usec)))
    if (execme(info, elem) < 0)
      break;
  calculate_timeout(info, tp);
  return (0);
}
