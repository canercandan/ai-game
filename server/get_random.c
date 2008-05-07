/*
** get_random.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May  3 17:16:51 2008 caner candan
** Last update Wed May  7 20:00:13 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

int		get_random(int max, int diff)
{
  double	val;
  int		res;

  while (42)
    {
      val = (double)max * random();
      if ((res = (int) (val / (RAND_MAX + 1.0)) % (max + 1)) != diff)
	break;
    }
  return (res);
}
