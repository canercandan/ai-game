/*
** create_world.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 17:26:46 2008 majdi toumi
** Last update Wed Apr 30 17:17:49 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "x.h"

t_zone		**create_world(int width, int lenght)
{
  t_zone	**world;
  int		i;

  if (width < 0 || lenght < 0)
    {
      fprintf(stdin, "create_world: your width and lenght must be an integer\n");
      exit(EXIT_FAIL);
    }
  world = xmalloc(sizeof(*world) * width);
  for (i = 0; i < width; i++)
    {
      world[i] = xmalloc(sizeof(**world) * lenght);
      memset(world[i], 0, sizeof(**world) * lenght);
    }
  /* FIXME -> function: initialiser map objet, ... */
  fill_ressources_world(world, width, lenght, width * length);
  return (world);
}
