/*
** rm_client_from_queue.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 17:35:17 2008 caner candan
** Last update Thu May  1 19:59:05 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

static void	first_elm(t_list **t)
{
  debug("first_elm()", -1);
  *t = (*t)->next;
  free(*t);
}

static void	loop_elm(t_list *elm, int socket)
{
  t_list	*next;

  debug("loop_elm()", -1);
  while (elm->next)
    {
      if (((t_queue *) elm->next->data)->client->socket != socket)
	{
	  elm = elm->next;
	  continue;
	}
      next = elm->next->next;
      free(elm->next);
      elm->next = next;
    }
}

void		rm_client_from_queue(t_list **t, int socket)
{
  debug("rm_client_from_queue()", -1);
  if (*t)
    {
      if (((t_queue *) (*t)->data)->client->socket == socket)
	first_elm(t);
      else
	loop_elm(*t, socket);
    }
}
