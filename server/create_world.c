/*
** create_world.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 17:26:46 2008 majdi toumi
** Last update Fri May  2 17:13:44 2008 caner candan
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

  debug("create_world()", 1);
  if (info->y < 0 || info->x < 0)
    {
      fprintf(stdin, "create_world: your width and lenght must be an integer\n");
      exit(EXIT_FAIL);
    }
  world = xmalloc(sizeof(*world) * info->y);
  for (i = 0; i < info->y; i++)
    {
      world[i] = xmalloc(sizeof(**world) * info->x);
      memset(world[i], 0, sizeof(**world) * info->x);
    }
  /* FIXME -> function: initialiser map objet, ... */
  fill_ressources_world(world, info);
  return (world);
}
