/*
** pop_client_from_list.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 21:51:51 2008 caner candan
** Last update Tue Apr 29 22:28:17 2008 caner candan
*/

#include <stdlib.h>
#include "zappy.h"
#include "server.h"

void		*pop_client_from_list(t_list **t, int socket)
{
  t_list	*elm;
  t_list	*tmp;
  void		*data;

  elm = *t;
  if (!elm)
    return ((void *) -1);
  while (elm)
    {
      if (((t_cli *) elm->data)->socket != socket)
	{
	  elm = elm->next;
	  continue;
	}
      tmp = elm->next;
      data = elm->data;
      free(elm);
      elm = tmp;
      return (data);
    }
  return (NULL);
}