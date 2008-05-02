/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Fri May  2 22:40:10 2008 florent hochwelker
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
  if (info->queue)
    {
      while ((elem = info->queue->data) && elem->time < cur_time)
	{
	  printf("je suis dans le while de scheduler:\n");
	  printf("elem = %d, elem->client->socket = %d\n",
		 (int)elem, elem->client->socket);
	  elem->f(elem->param, elem->client);
	  printf("ba oue c t sa\n");
	  pop_list(&info->queue);
	  /* 	  free(elem->param); */
	  /* 	  free(elem); */
	}
    }
  return (0);
}
