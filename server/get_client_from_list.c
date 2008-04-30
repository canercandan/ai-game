/*
** get_client_from_list.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 22:29:56 2008 caner candan
** Last update Wed Apr 30 12:27:39 2008 caner candan
*/

#include "server.h"

void		*get_client_from_list(t_list *t, int socket)
{
  t_list	*tmp;
  void		*data;

  if (!t)
    return ((void *) -1);
  while (t)
    {
      if (((t_cli *) t->data)->socket == socket)
	return (t->data);
      t = t->next;
    }
  return (NULL);
}
