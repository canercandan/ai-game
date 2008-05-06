/*
** calculate_timeout.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Mon May  5 20:46:08 2008 florent hochwelker
** Last update Tue May  6 18:45:19 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

static void	check_timeout_death(struct timeval *timeout,
				    t_info *info, void *tp)
{
  t_list	*clients;

  clients = info->clients;
  while (clients)
    {
      if (((t_client *)clients->data)->status == ST_CLIENT
	  && ((t_client *)clients->data)->hp < (unsigned int)(timeout->tv_sec))
	{
	  timeout->tv_sec = ((t_client *)clients->data)->hp -
	    ((struct timeval *)tp)->tv_sec;
	  timeout->tv_usec = 0;
	}
      clients = clients->next;
    }
}

void	calculate_timeout(t_info *info, void *tp)
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
	- ((struct timeval *)tp)->tv_sec;
      ((struct timeval *)info->timeout)->tv_usec =
	((struct timeval *)((t_queue *)info->queue->data)->time)->tv_usec
	- ((struct timeval *)tp)->tv_usec;
      if (((struct timeval *)info->timeout)->tv_sec < 0)
	((struct timeval *)info->timeout)->tv_sec = 0;
      if (((struct timeval *)info->timeout)->tv_usec < 0)
	((struct timeval *)info->timeout)->tv_usec = 0;
    }
  check_timeout_death(info->timeout, info, tp);
}
