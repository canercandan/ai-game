//
// main.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:37:03 2008 majdi toumi
// Last update Tue May 13 23:59:27 2008 jordan aubry
//

#include <irrlicht.h>
#include "observator_3d.h"

using namespace	irr;

int	main(int ac, char **av)
{
  t_obs	obs;

  parse_args(ac, av, &obs);
  init_obs(&obs);
  draw_rock(&obs, 1, 1, 5);
  draw_player(&obs, 1, 2, 0);
  while (DEVICE(obs.window->device)->run())
    {
      //msg_reception(obs);
      rm_rock(&obs, 1, 1, 5);
      draw_all(&obs);
    }
  free_obs(&obs);
  return (0);
}
