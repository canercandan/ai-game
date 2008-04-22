/*
** put_in_list.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue Apr 15 15:20:39 2008 majdi toumi
** Last update Tue Apr 22 14:48:43 2008 majdi toumi
*/

#include <stdlib.h>
#include "zappy.h"

void		put_in_list(t_list **begin, void *data)
{
  t_list	*new_begin;
  t_ressource	*ressource;

  new_begin = malloc(sizeof(*new_begin));
  ressource = malloc(sizeof(*ressource));
  ressource->name = strdup(data);
  if (*begin)
    (*begin)->prev = new_begin;
  new_begin->data = ressource;
  new_begin->next = *begin;
  new_begin->prev = 0;
  *begin = new_begin;
}
