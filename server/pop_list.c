/*
** pop_list.c for zappy in /home/candan_c/cu/rendu/project/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 20:27:36 2008 caner candan
** Last update Tue Apr 29 20:31:55 2008 caner candan
*/

#include <stdlib.h>
#include "zappy.h"

void		*pop_list(t_list **t)
{
  t_list	*tmp;
  void		*data;

  if (!(*t))
    return ((void *) -1);
  tmp = (*t)->next;
  data = (*t)->data;
  free(*t);
  *t = tmp;
  return (data);
}
