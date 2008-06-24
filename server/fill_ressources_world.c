/*
** fill_ressources_world.c<2> for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue Apr 15 14:26:44 2008 majdi toumi
** Last update Tue Jun 24 14:04:37 2008 majdi toumi
*/

#include <stdlib.h>
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

  max = info->x * info->y * info->nb_player * info->coeff;
  i = 0;
  while (i < max)
    {
      x = get_random(info->x, last_x);
      y = get_random(info->y, last_y);
      last_x = x;
      last_y = y;
      ressource = &gl_ressource[i % NB_INVENTORY];
      push_list(&(world[x][y].ressources), ressource);
      world[x][y].nb_egg = 0;
      i++;
    }
}
