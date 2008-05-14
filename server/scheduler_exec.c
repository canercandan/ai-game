/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Wed May 14 11:01:48 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "common.h"
#include "server.h"

int			scheduler_exec(t_info *info, void *tp)
{
  t_queue		*elem;

  while (info->queue && (elem = info->queue->data) &&
	 ((TIMEVAL(elem->time)->tv_sec <
	   TIMEVAL(tp)->tv_sec) ||
	  ((TIMEVAL(elem->time)->tv_sec ==
	    TIMEVAL(tp)->tv_sec) &&
	   TIMEVAL(elem->time)->tv_usec <=
	   TIMEVAL(tp)->tv_usec)))
    {
      if (elem->f(elem->param, elem->client, info) == LOOP_FOR_SEND)
	break;
      if (elem->idx_f == BIRD)
	obs_send_action(0, info, elem->idx_f,
			"");
      else
	obs_send_action(elem->client->id, info, elem->idx_f,
			elem->param);
      dump_client_position(info->clients);
      info->queue = info->queue->next;
      free(elem->param);
      free(elem->time);
      free(elem);
    }
  calculate_timeout(info, tp);
  return (0);
}
