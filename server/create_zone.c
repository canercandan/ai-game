/*
** create_zone.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 17:26:46 2008 majdi toumi
** Last update Thu Apr 10 18:15:39 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

t_zone		create_zone(t_info *info)
{
  t_zone	**zone;
  int		i;

  if (info->width < 0 || info->lenght < 0)
    {
      fprintf(stdin, "create_zone: your width and lenght must be an integer > 0\n");
      exit(EXIT_FAIL);
    }
  zone = xmalloc(sizeof(*zone) * info->width);
  for (i = 0; i < info->width)
    {
      zone[i] = xmalloc(sizeof(**zone) * info->lenght);
      memset(&zone[i], 0, info->lenght);
    }
  // AFTER -> function: remplir map objet, ...
  fill_ressources_zone(zone);
  return (zone);
}
