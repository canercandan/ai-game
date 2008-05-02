/*
** dump_zone.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 19:23:19 2008 majdi toumi
** Last update Fri May  2 16:39:04 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

static void		dump_ressources(t_list *ressource)
{
  fprintf(stdout, "\t + Ressources: ");
  while (ressource)
    {
      fprintf(stdout, "%s ", (char *)ressource->data);
      ressource = ressource->next;
    }
}

static void		dump_clients(t_list *clients)
{
  fprintf(stdout, "\t + Clients: ");
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

  for (i = 0; i < y; i++)
    {
      for (j = 0; j < x; j++)
	{
	  fprintf(stdout, "- [%d][%d]:\n", i, j);
	  /*
	    fprintf(stdout, "\t + Id deco: %d and is_movable: %s\n", 
	    zone[i][j].id_deco, zone[i][j].is_moveable ? "yes" : "no");
	  */
	  begin = zone[i][j].ressources;
	  dump_ressources(begin);
	  fprintf(stdout, "\n");
	  begin = zone[i][j].client;
	  dump_clients(begin);
	  fprintf(stdout, "\n");
	}
    }
}

