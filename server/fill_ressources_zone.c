/*
** fill_ressources_zone.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:55:56 2008 majdi toumi
** Last update Wed Apr 30 12:34:53 2008 caner candan
*/

#include "server.h"

void	fill_ressources_zone(t_zone **zone, int width, int lenght)
{
  int	i;
  int	j;

  for (i = 0; i < width; i++)
    {
      for (j = 0; j < lenght; j++)
	{
	  zone[i][j].id_deco = 42;
	}
    }
  if (DEBUG)
    dump_zone(zone, width, lenght);
}
