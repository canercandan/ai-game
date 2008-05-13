/*
** dump_clients.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 18:34:24 2008 caner candan
** Last update Tue May 13 23:39:14 2008 caner candan
*/

#include <stdio.h>
#include "observator_2d.h"

void		dump_clients(t_info *info)
{
  t_list	*t;

  t = info->clients;
  while (t)
    {
      printf("Clients id[%d], team[%s], level[%d], x[%d], y[%d], "
	     "direction[%d]\n",
	     CLIENT(t->data)->id, CLIENT(t->data)->team_name,
	     CLIENT(t->data)->level, CLIENT(t->data)->x,
	     CLIENT(t->data)->y, CLIENT(t->data)->direction);
      t = t->next;
    }
}
