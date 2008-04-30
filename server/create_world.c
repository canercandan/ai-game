/*
** create_world.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 17:26:46 2008 majdi toumi
** Last update Wed Apr 30 17:29:13 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "x.h"

t_zone		**create_world(t_info *info)
{
  t_zone	**world;
  int		i;

  if (info->width < 0 || info->lenght < 0)
    {
      fprintf(stdin, "create_world: your width and lenght must be an integer\n");
      exit(EXIT_FAIL);
    }
  world = xmalloc(sizeof(*world) * info->width);
  for (i = 0; i < info->width; i++)
    {
      world[i] = xmalloc(sizeof(**world) * info->lenght);
      memset(world[i], 0, sizeof(**world) * info->lenght);
    }
  /* FIXME -> function: initialiser map objet, ... */
  fill_ressources_world(world, info);
  return (world);
}
