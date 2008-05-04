/*
** fill_ressources_world.c<2> for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue Apr 15 14:26:44 2008 majdi toumi
** Last update Sun May  4 17:32:39 2008 caner candan
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"
#include "x.h"

void		fill_ressources_world(t_zone **world, t_info *info)
{
/*   t_ressource	*ressource; */
/*   int		max; */
/*   int		i; */
/*   int		x; */
/*   int		y; */

  (void) info;
  debug("fill_ressources_world()", 2);
  push_list(&(world[0][0].ressources), &gl_rock[0]);
  push_list(&(world[1][1].ressources), &gl_rock[1]);
  push_list(&(world[3][0].ressources), &gl_rock[2]);
  push_list(&(world[2][1].ressources), &gl_rock[3]);
  push_list(&(world[4][3].ressources), &gl_rock[4]);
  push_list(&(world[2][1].ressources), &gl_rock[5]);
  push_list(&(world[1][1].ressources), &gl_rock[0]);
/*   max = info->x * info->y * info->nb_player * COEFFICIENT; */
/*   for (i = 0; i < max; i++) */
/*     { */
/*       x = get_random(info->x - 1); */
/*       y = get_random(info->y - 1); */
/*       ressource = generate_ressources(START_LEVEL, i); */
/*       push_list(&(world[x][y].ressources), ressource); */
/*       printf("#DUMP WORLD#\t[%d][%d] -> [%s]\n", x, y, ressource->name); */
/*     } */
/*   if (DEBUG) */
/*     dump_world(world, info->x, info->y); */
}
