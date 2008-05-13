/*
** get_client_from_list.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:12:39 2008 caner candan
** Last update Tue May 13 19:13:46 2008 caner candan
*/

#include "observator_2d.h"

void	*get_client_from_list(t_list *t, int socket)
{
  if (!t)
    return ((void *) -1);
  while (t)
    {
      if (CLIENT(t->data)->socket == socket)
	return (t->data);
      t = t->next;
    }
  return (NULL);
}
