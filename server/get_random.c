/*
** get_random.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May  3 17:16:51 2008 caner candan
** Last update Sun May  4 15:06:01 2008 florent hochwelker
*/

#include <stdlib.h>
#include "server.h"

int		get_random(int max)
{
  double	val;

  val = (double)max * random();
  return ((int)(val / (RAND_MAX + 1.0)));
}
