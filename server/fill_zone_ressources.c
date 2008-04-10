/*
** fill_zone_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:22:42 2008 majdi toumi
** Last update Thu Apr 10 18:37:22 2008 majdi toumi
*/

#include "server.h"

void	fill_ressources_zone(t_zone **zone)
{
  int	i;
  int	j;

  for (i = 0; i < info->width; i++)
    {
      for (j = 0; j < info->lenght; j++)
	{
	  zone[i][j]->id_deco = 42;
	}
    }
  for (i = 0; i < info->width; i++)
    {
      for (j = 0; j < info->lenght; j++)
	{
	  printf(" %d ", zone[i][j]->id_deco);
	}
      printf("\n");
    }
}
