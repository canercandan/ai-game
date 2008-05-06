/*
** rm_client_from_queue.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 17:35:17 2008 caner candan
** Last update Mon May  5 22:07:28 2008 florent hochwelker
*/

#include <stdio.h>		/* a vier printf */
#include <stdlib.h>
#include <sys/time.h>
#include "server.h"

static void	first_elm(t_list **t)
{
  t_list	*tmp;

  debug("first_elm()", -1);
  tmp = *t;
  *t = (*t)->next;
  free(tmp);
  printf("first delete\n");
}

static void	loop_elm(t_list *elm, int socket)
{
  t_list	*next;

  debug("loop_elm()", -1);
  while (elm->next)
    {
      printf("while socket = %d\n", ((t_queue *)elm->data)->client->socket);
      if (((t_queue *)elm->next->data)->client->socket != socket)
	{
	  elm = elm->next;
	  continue;
	}
      next = elm->next->next;
      free(elm->next);
      elm->next = next;
      printf("loop delete\n");
    }
}

void			rm_client_from_queue(t_list **t, int socket,
					     t_info *info)
{
  struct timeval	tp;

  gettimeofday(&tp, NULL);
  debug("rm_client_from_queue()", -1);
  if (*t)
    {
      if (((t_queue *)(*t)->data)->client->socket == socket)
	first_elm(t);
      loop_elm(*t, socket);
    }
  calculate_timeout(info, &tp);
}
