/*
** rm_client_from_list.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 21:51:51 2008 caner candan
** Last update Sun May  4 13:53:10 2008 florent hochwelker
*/

#include <stdlib.h>
#include "server.h"

static void	*first_elm(t_list **t)
{
  t_list	*tmp;
  void		*data;

  debug("first_elm()", -1);
  tmp = *t;
  data = (*t)->data;
  *t = (*t)->next;
  free(tmp);
  return (data);
}

static void	*loop_elm(t_list *elm, void *data)
{
  t_list	*next;
  void		*ret_data;

  debug("loop_elm()", -1);
  while (elm->next)
    {
      if (elm->next->data != data)
	{
	  elm = elm->next;
	  continue;
	}
      next = elm->next->next;
      ret_data = elm->next->data;
      free(elm->next);
      elm->next = next;
      return (ret_data);
    }
  return (NULL);
}

void		*rm_client_from_list(t_list **t, void *data)
{
  debug("rm_client_from_list()", -1);
  if (!(*t))
    return ((void *) -1);
  if ((*t)->data == data)
    return (first_elm(t));
  return (loop_elm(*t, data));
}
