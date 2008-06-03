/*
** get_position_from_list.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May 14 12:05:20 2008 caner candan
** Last update Wed May 14 12:06:22 2008 caner candan
*/

#include "server.h"

int	get_position_from_list(t_list *t, void *data)
{
  int	i;

  i = 0;
  while (t)
    {
      if (t->data == data)
	return (i);
      i++;
      t = t->next;
    }
  return (-1);
}
