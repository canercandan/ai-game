/*
** rm_client_from_queue.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 17:35:17 2008 caner candan
** Last update Wed May 14 10:31:36 2008 majdi
*/

#include <stdlib.h>
#include <sys/time.h>
#include "server.h"
#include <stdio.h>

static void	first_elm(t_list **t)
{
  t_list	*tmp;
  t_queue	*queue;

  tmp = *t;
  *t = (*t)->next;
  queue = (t_queue *)tmp->data;
  if (queue->param)
    free(queue->param);
  if (queue->time)
    free(queue->time);
  free(queue);
  free(tmp);
}

static void	loop_elm(t_list *elm, int id)
{
  t_list	*next;

  while (elm->next)
    {
      if (((t_queue *)elm->next->data)->client->id != id)
	{
	  elm = elm->next;
	  continue;
	}
      next = elm->next->next;
      free(((t_queue *)elm->next->data)->param);
      free(((t_queue *)elm->next->data)->time);
      free(elm->next->data);
      free(elm->next);
      elm->next = next;
    }
}

void			rm_client_from_queue(t_list **t, int id,
					     t_info *info)
{
  struct timeval	tp;

  gettimeofday(&tp, NULL);
  while (*t && ((t_queue *)(*t)->data)->client->id == id)
    first_elm(t);
  if (*t)
    loop_elm(*t, id);
  calculate_timeout(info, &tp);
}
