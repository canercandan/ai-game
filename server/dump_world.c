/*
** dump_zone.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 19:23:19 2008 majdi toumi
** Last update Mon May  5 17:40:08 2008 majdi toumi
*/

#include <stdio.h>
#include "server.h"

static void		dump_ressources(t_list *ressource)
{
  debug("dump_ressources()", 4);
  while (ressource)
    {
      fprintf(stdout, "%s ", (char *)ressource->data);
      ressource = ressource->next;
    }
}

static void		dump_clients(t_list *clients)
{
  debug("dump_clients()", 4);
  while (clients)
    {
      fprintf(stdout, "%s ", (char *)clients->data);
      clients = clients->next;
    }
}

void		dump_world(t_zone **zone, int y, int x)
{
  int		i;
  int		j;
  t_list	*begin;

  debug("dump_world()", 3);
  for (i = 0; i < x; i++)
    {
      for (j = 0; j < y; j++)
	{
	  /* fprintf(stdout, "- [%d][%d]:\n", i, j); */
	  /*
	    fprintf(stdout, "\t + Id deco: %d and is_movable: %s\n",
	    zone[i][j].id_deco, zone[i][j].is_moveable ? "yes" : "no");
	  */
	  begin = zone[i][j].ressources;
	  dump_ressources(begin);
/* 	  fprintf(stdout, "\n"); */
	  begin = zone[i][j].clients;
	  dump_clients(begin);
/* 	  fprintf(stdout, "\n"); */
	}
    }
}
