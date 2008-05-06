/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Mon May  5 21:59:41 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "server.h"

int			scheduler_exec(t_info *info)
{
  t_queue		*elem;
  struct timeval	tp;

  gettimeofday(&tp, NULL);
  while (info->queue && (elem = info->queue->data)
	 && ((struct timeval *)elem->time)->tv_sec <= tp.tv_sec
	 && ((struct timeval *)elem->time)->tv_usec <= tp.tv_usec)
    {
      if (elem->f(elem->param, elem->client, info) == LOOP_FOR_SEND)
	break;
      dump_client_position(info->clients); /* debug pour see */
      info->queue = info->queue->next;
      free(elem->param);
      free(elem->time);
      free(elem);
    }
  calculate_timeout(info, &tp);
  return (0);
}
