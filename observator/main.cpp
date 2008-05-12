//
// main.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:37:03 2008 majdi toumi
// Last update Mon May 12 14:53:09 2008 caner candan
//

#include <irrlicht.h>
#include "observator.h"

using namespace	irr;

int	main(int ac, char **av)
{
  t_obs	obs;

  init_obs(&obs);
  if (parse_args(ac, av, &obs) < 0)
    main_usage();
  draw_rock(&obs, 0, 0, 2);
  draw_rock(&obs, 10, 0, 1);
  draw_player(&obs, 1, 2, 0);
  while (DEVICE(obs.window->device)->run())
    {
      //msg_reception(obs);
      draw_all(&obs);
    }
  return (0);
}
