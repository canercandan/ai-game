/*
** dump_clients.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 19:23:19 2008 majdi toumi
** Last update Mon Jun 23 01:14:25 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

void	dump_clients(t_list *clients)
{
  while (clients)
    {
      fprintf(stdout, "%s ", (char *)clients->data);
      clients = clients->next;
    }
}
