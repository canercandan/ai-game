/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Sun May  4 14:27:37 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include "server.h"

static void		calculate_timeout(t_info *info, unsigned int cur_time)
{
  struct timeval	tp;
  struct timezone	tzp;

  gettimeofday(&tp, &tzp);
  if (info->time >= 1)
    {
      if (info->queue == 0)
	{
	  ((struct timeval *)info->timeout)->tv_sec = 0;
	  ((struct timeval *)info->timeout)->tv_usec = 0;
	}
      else
	((struct timeval *)info->timeout)->tv_sec =
	  ((t_queue *)info->queue->data)->time - cur_time;
    }
}

int		scheduler_exec(t_info *info)
{
  t_queue	*elem;
  unsigned int	cur_time;

  cur_time = time(NULL);
  while (info->queue && (elem = info->queue->data) && elem->time <= cur_time)
    {
      dump_client_position(info->clients);
      elem->f(elem->param, elem->client, info);
      dump_client_position(info->clients);
      info->queue = info->queue->next;
      free(elem->param);
      free(elem);
    }
  calculate_timeout(info, cur_time);
  return (0);
}
