/*
** push_list.c for zappy in /home/candan_c/cu/rendu/project/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 20:25:24 2008 caner candan
** Last update Wed Apr 30 19:16:06 2008 florent hochwelker
*/

#include <stdlib.h>
#include "server.h"
#include "x.h"

void		push_list(t_list **t, void *data)
{
  t_list	*new;

  debug("push_list()", -1);
  if (!(new = xmalloc(sizeof(*new))))
    exit(-1);
  new->data = data;
  new->next = *t;
  *t = new;
}
