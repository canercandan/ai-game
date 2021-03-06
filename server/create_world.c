/*
** create_world.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 17:26:46 2008 majdi toumi
** Last update Mon Jun 23 01:22:56 2008 caner candan
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server.h"
#include "x.h"

t_zone		**create_world(t_info *info)
{
  t_zone	**world;
  int		i;

  if (info->x < 0 || info->y < 0)
    {
      fprintf(stdin, ERR_SIZE_MAP);
      exit(EXIT_FAIL);
    }
  world = xmalloc(sizeof(*world) * info->x);
  i = 0;
  while (i < info->x)
    {
      world[i] = xmalloc(sizeof(**world) * info->y);
      memset(world[i], 0, sizeof(**world) * info->y);
      i++;
    }
  fill_ressources_world(world, info);
  return (world);
}
