/*
** count_list.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 18:13:29 2008 caner candan
** Last update Wed Apr 30 18:14:59 2008 caner candan
*/

#include "server.h"

int	count_list(t_list *t)
{
  int	i;

  for (i = 0; t; i++)
    t = t->next;
  return (i);
}
