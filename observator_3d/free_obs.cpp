//
// free_obs.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:33 2008 majdi toumi
// Last update Mon May 12 14:53:17 2008 caner candan
//

#include <stdlib.h>
#include "observator.h"

void	free_obs(t_obs *obs)
{
  int	i;

  for (i = 0; i < obs->x; i++)
    free(obs->matrix[i]);
  free(obs->matrix);
  free(obs->window);
  free(obs->item);
}
