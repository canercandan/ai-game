//
// init_obs.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:41:45 2008 majdi toumi
// Last update Mon May 12 13:47:50 2008 majdi toumi
//

#include <stdlib.h>
#include "observator.h"

t_obs		*init_obs(char *host, char *port)
{
  t_obs		*obs;

  obs = (t_obs *) malloc(sizeof(*obs));
  init_socket(obs, host, port);
  obs->window = init_window();
  init_map_size(obs);
  obs->matrix = init_matrix(obs);
  init_item(obs);
  init_case(obs);
  return (obs);
}
