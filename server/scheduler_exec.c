/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Sun May  4 18:59:49 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include "server.h"

static void		calculate_timeout(t_info *info, struct timeval *tp)
{
  if (info->queue == 0)
    {
      ((struct timeval *)info->timeout)->tv_sec = 0;
      ((struct timeval *)info->timeout)->tv_usec = 0;
    }
  else
    {
      ((struct timeval *)info->timeout)->tv_sec =
	((struct timeval *)((t_queue *)info->queue->data)->time)->tv_sec
	- tp->tv_sec;
      ((struct timeval *)info->timeout)->tv_usec =
	((struct timeval *)((t_queue *)info->queue->data)->time)->tv_usec
	- tp->tv_usec;
      if (((struct timeval *)info->timeout)->tv_usec < 0)
	((struct timeval *)info->timeout)->tv_usec = 0;
    }
}

int			scheduler_exec(t_info *info)
{
  t_queue		*elem;
  struct timeval	tp;

  gettimeofday(&tp, NULL);
  while (info->queue && (elem = info->queue->data)
	 && ((struct timeval *)elem->time)->tv_sec <= tp.tv_sec
	 && ((struct timeval *)elem->time)->tv_usec <= tp.tv_usec)
    {
      dump_client_position(info->clients); /* debug pour see */
      elem->f(elem->param, elem->client, info);
      dump_client_position(info->clients); /* debug pour see */
      info->queue = info->queue->next;
      free(elem->param);
      free(elem->time);
      free(elem);
    }
  calculate_timeout(info, &tp);
  return (0);
}
