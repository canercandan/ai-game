/*
** rm_client_from_queue.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 17:35:17 2008 caner candan
** Last update Thu May  8 13:17:53 2008 caner candan
*/

#include <stdlib.h>
#include <sys/time.h>
#include "server.h"

static void	first_elm(t_list **t)
{
  t_list	*tmp;

  tmp = *t;
  *t = (*t)->next;
  free(((t_queue *)tmp->data)->param);
  free(((t_queue *)tmp->data)->time);
  free(tmp->data);
  free(tmp);
}

static void	loop_elm(t_list *elm, int socket)
{
  t_list	*next;

  while (elm->next)
    {
      if (((t_queue *)elm->next->data)->client->socket != socket)
	{
	  elm = elm->next;
	  continue;
	}
      next = elm->next->next;
      free(((t_queue *)elm->data)->param);
      free(((t_queue *)elm->data)->time);
      free(elm->data);
      free(elm);
      free(elm->next);
      elm->next = next;
    }
}

void			rm_client_from_queue(t_list **t, int socket,
					     t_info *info)
{
  struct timeval	tp;

  gettimeofday(&tp, NULL);
  while (*t && ((t_queue *)(*t)->data)->client->socket == socket)
    first_elm(t);
  if (*t)
    loop_elm(*t, socket);
  calculate_timeout(info, &tp);
}
