/*
** pop_all_list.c for zappy in /home/candan_c/cu/rendu/project/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 20:32:34 2008 caner candan
** Last update Mon May 12 15:55:20 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

void	pop_all_list(t_list **t)
{
  void	*data;

  debug("pop_all_list()", -1);
  while (42)
    if ((long) (data = pop_list(t)) < 0)
      break;
}
