/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Wed May  7 10:57:52 2008 florent hochwelker
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
	 ((((struct timeval *)elem->time)->tv_sec <
	   ((struct timeval *)tp)->tv_sec) ||
	  ((((struct timeval *)elem->time)->tv_sec ==
	    ((struct timeval *)tp)->tv_sec) &&
	   ((struct timeval *)elem->time)->tv_usec <
	   ((struct timeval *)tp)->tv_usec)))
    {
      if (elem->f(elem->param, elem->client, info) == LOOP_FOR_SEND)
	{
	  printf("break du au LOOP_FOR_SEND\n");
	  break;
	}
      dump_client_position(info->clients); /* debug pour see */
      info->queue = info->queue->next;
      free(elem->param);
      free(elem->time);
      free(elem);
    }
  calculate_timeout(info, tp);
  return (0);
}
