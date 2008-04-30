/*
** fill_ressources_world.c<2> for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue Apr 15 14:26:44 2008 majdi toumi
** Last update Wed Apr 30 17:19:58 2008 majdi toumi
*/

#include "server.h"

void		fill_ressources_world(t_zone **world, int width, int lenght)
{
  /*
  t_ressources	ressource[max];
  int	max;
  int	j;
  int	nb;

  nb = ;
  max = width * length * COEFF_OBJECT;
  for (i = 0; i < max;  i++)
    ressource[i] = generate_ressources(1);

  for (i = 0; i < width; i++)
    {
      for (j = 0; j < lenght; j++)
	{
	  world[i][j].ressources = generate_ressources();
	  world[i][j].id_deco = 42;
	  world[i][j].is_moveable = 1;
	}
    }
  */

  if (DEBUG)
    dump_world(world, width, lenght);
}
