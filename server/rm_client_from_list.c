/*
** rm_client_from_list.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 21:51:51 2008 caner candan
** Last update Thu May  1 20:08:42 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

static void	*first_elm(t_list **t)
{
  void		*data;

  debug("first_elm()", -1);
  data = (*t)->data;
  *t = (*t)->next;
  free(*t);
  return (data);
}

static void	*loop_elm(t_list *elm, int socket)
{
  t_list	*next;
  void		*data;

  debug("loop_elm()", -1);
  while (elm->next)
    {
      if (((t_client *) elm->next->data)->socket != socket)
	{
	  elm = elm->next;
	  continue;
	}
      next = elm->next->next;
      data = elm->next->data;
      free(elm->next);
      elm->next = next;
      return (data);
    }
  return (NULL);
}

void		*rm_client_from_list(t_list **t, int socket)
{
  debug("rm_client_from_list()", -1);
  if (!(*t))
    return ((void *) -1);
  if (((t_client *) (*t)->data)->socket == socket)
    return (first_elm(t));
  return (loop_elm(*t, socket));
}
