/*
** put_in_list.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue Apr 15 15:20:39 2008 majdi toumi
** Last update Wed Apr 30 12:29:45 2008 majdi toumi
*/

#include <stdlib.h>
#include "server.h"

void		put_in_list(t_list **begin, void *data)
{
  t_list	*new_begin;
  t_ressource	*ressource;

  new_begin = malloc(sizeof(*new_begin));
  ressource = malloc(sizeof(*ressource));
  ressource->name = strdup(data);
  new_begin->prev = 0;
  new_begin->data = ressource;
  new_begin->next = *begin;
  *begin = new_begin;
}
