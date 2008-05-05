/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Mon May  5 18:28:03 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include "server.h"

static void		calculate_timeout(t_info *info, struct timeval *tp)
{
  if (info->queue == 0)
    {
      ((struct timeval *)info->timeout)->tv_sec = -1;
      ((struct timeval *)info->timeout)->tv_usec = -1;
    }
  else
    {
      ((struct timeval *)info->timeout)->tv_sec =
	((struct timeval *)((t_queue *)info->queue->data)->time)->tv_sec
	- tp->tv_sec;
      ((struct timeval *)info->timeout)->tv_usec =
	((struct timeval *)((t_queue *)info->queue->data)->time)->tv_usec
	- tp->tv_usec;
      if (((struct timeval *)info->timeout)->tv_sec < 0)
       	((struct timeval *)info->timeout)->tv_sec = 0;
      if (((struct timeval *)info->timeout)->tv_usec < 0)
	((struct timeval *)info->timeout)->tv_usec = 0;
    }
}

/* static void		check_dead_clients(t_info *info) */
/* { */
/*   t_list		*clients; */

/*   clients = info->clients; */
/*   while (clients) */
/*     { */
/*       /\*       if (((t_client *)clients->data)->status == ST_CLIENT) *\/ */
/*       /\* 	{ *\/ */
/*       /\* 	  ((t_client *)clients->data)->hp -= info-> *\/ */
/*       /\* 	    } *\/ */
/*       clients = clients->next; */
/*     } */
/* } */

int			scheduler_exec(t_info *info)
{
  t_queue		*elem;
  struct timeval	tp;

  gettimeofday(&tp, NULL);
  /*   check_dead_clients(info); */
  while (info->queue && (elem = info->queue->data)
	 && ((struct timeval *)elem->time)->tv_sec <= tp.tv_sec
	 && ((struct timeval *)elem->time)->tv_usec <= tp.tv_usec)
    {
      dump_client_position(info->clients); /* debug pour see */
      if (elem->f(elem->param, elem->client, info) == LOOP_FOR_SEND)
	return (0);
      dump_client_position(info->clients); /* debug pour see */
      info->queue = info->queue->next;
      free(elem->param);
      free(elem->time);
      free(elem);
    }
  calculate_timeout(info, &tp);
  return (0);
}
