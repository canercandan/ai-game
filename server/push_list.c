/*
** push_list.c for zappy in /home/candan_c/cu/rendu/project/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 20:25:24 2008 caner candan
** Last update Tue Apr 29 20:33:00 2008 caner candan
*/

#include <stdlib.h>
#include "zappy.h"

void		push_list(t_list **t, void *data)
{
  t_list	*new;

  if (!(new = xmalloc(sizeof(*new))))
    exit(-1);
  new->data = data;
  new->next = *t;
  *t = new;
}
