/*
** rm_data_from_list.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May  5 17:46:20 2008 caner candan
** Last update Thu May  8 13:17:42 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

static void	*first_elm(t_list **t)
{
  t_list	*tmp;
  void		*data;

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

void		*rm_data_from_list(t_list **t, void *data)
{
  if (!(*t))
    return ((void *) -1);
  if ((*t)->data == data)
    return (first_elm(t));
  return (loop_elm(*t, data));
}
