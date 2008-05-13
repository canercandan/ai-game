/*
** show_clients_from_list.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 17:07:30 2008 caner candan
** Last update Tue May 13 23:02:03 2008 majdi
*/

#include <stdio.h>
#include "server.h"

void		show_clients_from_list(t_list *t)
{
  t_client	*client;

  debug("show_clients_from_list()", -1);
  printf("\n-- START -- Clients list --\n");
  while (t)
    {
      client = t->data;
      printf("-- fd: %02d --\n", client->id);
      t = t->next;
    }
  printf("-- END -- Clients list --\n\n");
}
