/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Sat May  3 00:17:38 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

int		scheduler_exec(t_info *info)
{
  unsigned int	cur_time;
  t_queue	*elem;

  cur_time = time(0);
  while (info->queue && (elem = info->queue->data) && elem->time <= cur_time)
    {
      printf("un truc dans scheduler\n");
      elem->f(elem->param, elem->client);
      info->queue = info->queue->next;
      free(elem->param);
      free(elem);
    }
  if (info->queue == 0)
    ((struct timeval *)info->timeout)->tv_sec = 0;
  else
    ((struct timeval *)info->timeout)->tv_sec =
      ((t_queue *)info->queue->data)->time - cur_time;
  return (0);
}
