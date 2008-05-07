/*
** fill_ressources_world.c<2> for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue Apr 15 14:26:44 2008 majdi toumi
** Last update Wed May  7 20:15:18 2008 caner candan
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"
#include "common.h"
#include "x.h"

t_ressource	gl_ressource[] = {
  {LINEMATE, "linemate", 0},
  {DERAUMERE, "deraumere", 0},
  {SIBUR, "sibur", 0},
  {MENDIANE, "mendiane", 0},
  {PHIRAS, "phiras", 0},
  {THYSTAME, "thystame", 0},
  {NOURRITURE, "nourriture", 0},
  {-1, 0, 0}
};

void		fill_ressources_world(t_zone **world, t_info *info)
{
  static int	last_x = -1;
  static int	last_y = -1;
  t_ressource	*ressource;
  int		max;
  int		i;
  int		x;
  int		y;

  debug("fill_ressources_world()", 2);
  max = info->x * info->y * info->nb_player * COEFFICIENT;
  for (i = 0; i < max; i++)
    {
      x = get_random(info->x, last_x);
      y = get_random(info->y, last_y);
      last_x = x;
      last_y = y;
      ressource = &gl_ressource[i % NB_INVENTORY];
      push_list(&(world[x][y].ressources), ressource);
      printf("#DUMP WORLD#\t[%d][%d] -> [%s]\n", x, y, ressource->name);
    }
}
