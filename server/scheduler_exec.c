/*
** scheduler_exec.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 19:23:49 2008 florent hochwelker
** Last update Fri May  2 22:03:48 2008 florent hochwelker
*/

#include <sys/time.h>
#include <stdlib.h>
#include "server.h"

int		scheduler_exec(t_info *info)
{
  unsigned int	cur_time;
  t_list	*begin;
  t_queue	*elem;

  cur_time = time(0);
  if ((begin = info->queue))
    {
      elem = begin->data;
      while (elem->time < cur_time)
	{
	  elem->f(elem->param, elem->client);
	  begin = begin->next;
	  free(elem->param);
	  free(elem);
	  elem = begin->data;
	}
    }
  return (0);
}
