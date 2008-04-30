/*
** show_clients_from_list.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 17:07:30 2008 caner candan
** Last update Wed Apr 30 17:19:30 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

void	show_clients_from_list(t_list *t)
{
  t_cli	*cli;

  printf("-- START -- Clients list --\n");
  while (t)
    {
      cli = t->data;
      printf("-- fd: %02d --\n");
      t = t->next;
    }
  printf("-- END -- Clients list --\n");
}
