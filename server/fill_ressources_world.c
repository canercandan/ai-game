/*
** fill_ressources_world.c<2> for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue Apr 15 14:26:44 2008 majdi toumi
** Last update Fri May  2 18:00:00 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"
#include "x.h"

void		fill_ressources_world(t_zone **world, t_info *info)
{
  t_ressource	**ressource;
  int		max;
  int		i;
  int		x;
  int		y;

  debug("fill_ressources_world()", 2);
  max = info->y * info->x * info->nb_player * COEFFICIENT;
  ressource = xmalloc(sizeof(*ressource) * max);
  for (i = 0; i < max;  i++)
    ressource[i] = generate_ressources(1, i);
  for (i = 0; i < max; i++)
    {
      x = (int)(rand() / (double)RAND_MAX * (info->x - 1));
      y = (int)(rand() / (double)RAND_MAX * (info->y - 1));
      push_list(&(world[y][x].ressources), ressource[i]);
    }
  if (DEBUG)
    dump_world(world, info->y, info->x);
}
