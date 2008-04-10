/*
** create_zone.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 17:26:46 2008 majdi toumi
** Last update Thu Apr 10 19:55:28 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy.h"

t_zone		**create_zone(int width, int lenght)
{
  t_zone	**zone;
  int		i;

  if (width < 0 || lenght < 0)
    {
      fprintf(stdin, "create_zone: your width and lenght must be an integer > 0\n");
      exit(EXIT_FAIL);
    }
  zone = xmalloc(sizeof(*zone) * width);
  for (i = 0; i < width; i++)
    {
      zone[i] = xmalloc(sizeof(**zone) * lenght);
      memset(zone[i], 0, sizeof(**zone) * lenght);
    }
  // FIXME -> function: remplir map objet, ...
  fill_ressources_zone(zone, width, lenght);
  return (zone);
}
