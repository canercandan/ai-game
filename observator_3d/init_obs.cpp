//
// init_obs.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:41:45 2008 majdi toumi
// Last update Tue May 13 13:51:43 2008 jordan aubry
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "observator_3d.h"

void	init_obs(t_obs *obs)
{
  init_socket(obs);
  obs->window = init_window();
  init_map_size(obs);
  obs->matrix = init_matrix(obs);
  init_item(obs);
  init_case(obs);
}
