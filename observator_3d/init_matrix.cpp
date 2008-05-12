//
// init_matrix.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:47 2008 majdi toumi
// Last update Mon May 12 19:22:00 2008 caner candan
//

#include <stdlib.h>
#include "observator_3d.h"
#include "common.h"

t_matrix	**init_matrix(t_obs *obs)
{
  t_matrix	**m;
  int		i;
  int		j;
  int		k;

  m = (t_matrix **) malloc(sizeof(*m) * obs->x);
  for (i = 0; i < obs->x; i++)
    {
      m[i] = (t_matrix *) malloc(sizeof(**m) * obs->y);
      for (j = 0; j < obs->y; j++)
	{
	  m[i][j].move = 1;
	  m[i][j].level = 1;
	  for (k = 0; k < NB_RESSOURCE; k++)
	    m[i][j].item[k] = 0;
	}
    }
  return (m);
}
