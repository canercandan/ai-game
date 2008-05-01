/*
** pop_client_from_list.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 21:51:51 2008 caner candan
** Last update Thu May  1 16:05:12 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

static void	free_client(t_list *t)
{
  free(t->data);
  free(t);
}

void		*pop_client_from_list(t_list **t, int socket)
{
  t_list	*elm;
  void		*data;

  debug("pop_client_from_list()", -1);
  elm = *t;
  if (!elm)
    return ((void *) -1);
  while (elm->next)
    {
      if (((t_client *) elm->next->data)->socket != socket)
	{
	  elm = elm->next;
	  continue;
	}
      elm->next = elm->next->next;
      data = elm->next->data;
      free_client(elm->next);
      return (data);
    }
  return (NULL);
}
