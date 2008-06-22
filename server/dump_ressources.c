/*
** dump_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 19:23:19 2008 majdi toumi
** Last update Mon Jun 23 01:14:32 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

void		dump_ressources(t_list *begin)
{
  t_ressource	*ressource;

  while (begin)
    {
      ressource = (t_ressource *)begin->data;
      printf("%s ", (char *)ressource->name);
      begin = begin->next;
    }
  printf("\n");
}
