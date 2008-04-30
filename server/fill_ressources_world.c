/*
** fill_ressources_world.c<2> for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue Apr 15 14:26:44 2008 majdi toumi
** Last update Wed Apr 30 19:00:03 2008 majdi toumi
*/

#include <stdlib.h>
#include "server.h"
#include "x.h"

void		fill_ressources_world(t_zone **world, t_info *info)
{
  t_ressource	**ressource;
  int	max;
  int	i;
  int	x;
  int	y;

  max = info->width * info->lenght * info->nb_player * COEFFICIENT;
  *ressource = xmalloc(sizeof(*ressource) * max);
  for (i = 0; i < max;  i++)
    ressource[i] = generate_ressources(1, i);
  for (i = 0; i < max; i++)
    {
      x = (int)(rand() / (double)RAND_MAX * (info->width - 1));
      y = (int)(rand() / (double)RAND_MAX * (info->lenght - 1));
      push_list(&(world[x][y].ressources), ressource[i]);
    }
  if (DEBUG)
    dump_world(world, info->width, info->lenght);
}
