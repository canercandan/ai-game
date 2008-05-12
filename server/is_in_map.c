/*
** is_in_map.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Mon May 12 19:28:05 2008 majdi toumi
** Last update Mon May 12 19:28:06 2008 majdi toumi
*/

#include "server.h"
#include "common.h"

void	is_in_map(t_info *info, int *x, int *y)
{
  if (*x < 0)
    *x = info->x - ABS(*x % info->x);
  if (*y < 0)
    *y = info->y - ABS(*y % info->x);
  *x %= info->x;
  *y %= info->y;
}
