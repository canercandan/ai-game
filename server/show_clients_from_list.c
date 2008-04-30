/*
** show_clients_from_list.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 17:07:30 2008 caner candan
** Last update Wed Apr 30 17:24:03 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

void	show_clients_from_list(t_list *t)
{
  t_cli	*cli;

  debug("show_clients_from_list()", -1);
  printf("-- START -- Clients list --\n");
  while (t)
    {
      cli = t->data;
      printf("-- fd: %02d --\n", cli->socket);
      t = t->next;
    }
  printf("-- END -- Clients list --\n");
}
