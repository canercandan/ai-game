/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Fri May  2 22:49:23 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

int		scheduler_exec(t_info *info)
{
  unsigned int	cur_time;
  t_list	*begin;
  t_queue	*elem;

  cur_time = time(0);
  begin = info->queue;
  while (info->queue && (elem = info->queue->data) && elem->time < cur_time)
    {
      elem->f(elem->param, elem->client);
      info->queue = info->queue->next;
      free(elem->param);
      free(elem);
    }
  if (info->queue == 0)
    ((struct timeval *)info->timeout)->tv_sec = 0;
  return (0);
}
