/*
** fill_ressources_world.c<2> for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue Apr 15 14:26:44 2008 majdi toumi
** Last update Wed Apr 30 13:35:51 2008 majdi toumi
*/

#include "server.h"

void	fill_ressources_world(t_zone **world, int width, int lenght)
{
  int	i;
  int	j;

  for (i = 0; i < width; i++)
    {
      for (j = 0; j < lenght; j++)
	{
	  world[i][j].ressources = 0; /* generate */
	  world[i][j].id_deco = 42;
	  world[i][j].is_moveable = 1;
	}
    }
  if (DEBUG)
    dump_world(world, width, lenght);
}
