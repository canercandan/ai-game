/*
** dump_zone.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 19:23:19 2008 majdi toumi
** Last update Mon Apr 14 15:33:13 2008 majdi toumi
*/

#include <stdio.h>
#include "zappy.h"

void		dump_zone(t_zone **zone, int width, int lenght)
{
  int		i;
  int		j;
  t_list	*begin;

  for (i = 0; i < width; i++)
    {
      for (j = 0; j < lenght; j++)
	{
	  fprintf(stdout, "- [%d][%d]:\n", i, j);
	  begin = zone[i][j].ressources;
	  dump_ressources(begin);
	  fprintf(stdout, "\n");
	  begin = zone[i][j].clients;
	  dump_clients(begin);
	  fprintf(stdout, "\n");
	}
    }
}

void		dump_ressources(t_list *ressource)
{
  fprintf(stdout, "\t + Ressources: ");
  while (ressource)
    {
      fprintf(stdout, "%s ", (char *)ressource->data);
      ressource = ressource->next;
    }
}

void		dump_clients(t_list *clients)
{
  fprintf(stdout, "\t + Clients: ");
  while (clients)
    {
      fprintf(stdout, "%s ", (char *)clients->data);
      clients = clients->next;
    }
}
