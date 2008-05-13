/*
** count_list_from_clients.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 21:55:36 2008 caner candan
** Last update Tue May 13 21:58:32 2008 caner candan
*/

#include "server.h"

int	count_list_from_clients(t_list *t)
{
  int	i;

  i = 0;
  while (t)
    {
      if (CLIENT(t->data)->status == ST_CLIENT ||
	  CLIENT(t->data)->status == ST_DISCONNECT)
	i++;
      t = t->next;
    }
  return (i);
}
