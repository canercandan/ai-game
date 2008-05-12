/*
** calculate_timeout.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Mon May  5 20:46:08 2008 florent hochwelker
** Last update Mon May 12 16:31:23 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

static void	timeout_ajust(struct timeval *timeout)
{
  if (timeout->tv_usec < 0)
    {
      timeout->tv_usec += 1e6;
      timeout->tv_sec--;
    }
  if (timeout->tv_sec < 0)
    timeout->tv_sec = 0;
}

static void	check_timeout_death(struct timeval *timeout,
				    t_info *info, void *tp)
{
  t_list	*clients;

  clients = info->clients;
  while (clients)
    {
      if ((CLIENT(clients->data)->status == ST_CLIENT ||
	   CLIENT(clients->data)->status == ST_DISCONNECT) &&
	  (((((unsigned int)CLIENT(clients->data)->hp) <
	     (unsigned int)(timeout->tv_sec) + TIMEVAL(tp)->tv_sec ||
	     (((unsigned int)CLIENT(clients->data)->hp) ==
	      (unsigned int)(timeout->tv_sec) + TIMEVAL(tp)->tv_sec &&
	      ((CLIENT(clients->data)->hp -
		(int)CLIENT(clients->data)->hp)) * 1e6 <
	      (unsigned int)(timeout->tv_usec) + TIMEVAL(tp)->tv_usec))) ||
	   (timeout->tv_sec == -1 && timeout->tv_usec == -1)))
	{
	  timeout->tv_sec = CLIENT(clients->data)->hp - TIMEVAL(tp)->tv_sec;
	  timeout->tv_usec = ((CLIENT(clients->data)->hp -
			       (int)CLIENT(clients->data)->hp)) * 1e6  -
	    TIMEVAL(tp)->tv_usec;
	  timeout_ajust(timeout);
	}
      clients = clients->next;
    }
}

void	calculate_timeout(t_info *info, void *tp)
{
  if (info->queue == 0)
    {
      TIMEVAL(info->timeout)->tv_sec = -1;
      TIMEVAL(info->timeout)->tv_usec = -1;
    }
  else
    {
      TIMEVAL(info->timeout)->tv_sec =
	TIMEVAL(((t_queue *)info->queue->data)->time)->tv_sec
	- TIMEVAL(tp)->tv_sec;
      TIMEVAL(info->timeout)->tv_usec =
	TIMEVAL(((t_queue *)info->queue->data)->time)->tv_usec
	- TIMEVAL(tp)->tv_usec;
      if (TIMEVAL(info->timeout)->tv_sec < 0)
	TIMEVAL(info->timeout)->tv_sec = 0;
      if (TIMEVAL(info->timeout)->tv_usec < 0)
	TIMEVAL(info->timeout)->tv_usec = 0;
    }
  check_timeout_death(info->timeout, info, tp);
}
