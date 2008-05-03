/*
** rm_client_from_queue.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 17:35:17 2008 caner candan
** Last update Sat May  3 17:52:23 2008 florent hochwelker
*/

#include <stdlib.h>
#include "server.h"

static void	first_elm(t_list **t)
{
  t_list	*tmp;

  debug("first_elm()", -1);
  tmp = *t;
  *t = (*t)->next;
  free(tmp);
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
      if (((t_queue *)(*t)->data)->client->socket == socket)
	first_elm(t);
      else
	loop_elm(*t, socket);
    }
}
