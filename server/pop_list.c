/*
** pop_list.c for zappy in /home/candan_c/cu/rendu/project/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 20:27:36 2008 caner candan
** Last update Wed Apr 30 17:30:06 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

void		*pop_list(t_list **t)
{
  t_list	*tmp;
  void		*data;

  debug("pop_list()", -1);
  if (!(*t))
    return ((void *) -1);
  tmp = (*t)->next;
  data = (*t)->data;
  free(*t);
  *t = tmp;
  return (data);
}
