/*
** dump_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 19:23:19 2008 majdi toumi
** Last update Tue May  6 15:30:12 2008 majdi toumi
*/

#include <stdio.h>
#include "server.h"

void		dump_ressources(t_list *begin)
{
  t_ressource	*ressource;

  debug("dump_ressources()", 4);
  while (begin)
    {
      ressource = (t_ressource *)begin->data;
      printf("%s ", (char *)ressource->name);
      begin = begin->next;
    }
  printf("\n");
}
