/*
** count_list_with_same_lvl.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 15:35:03 2008 caner candan
** Last update Mon Jun 23 07:00:16 2008 florent hochwelker
*/

#include "server.h"

int	count_list_with_same_lvl(t_list *t, int lvl)
{
  int	i;

  i = 0;
  while (t)
    {
      if (CLIENT(t->data)->level == lvl &&
	  (CLIENT(t->data)->status == ST_CLIENT ||
	   CLIENT(t->data)->status == ST_DISCONNECT))
	i++;
      t = t->next;
    }
  return (i);
}
