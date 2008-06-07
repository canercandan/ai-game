//
// main.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:37:03 2008 majdi toumi
// Last update Fri Jun  6 20:01:44 2008 florent hochwelker
//

#include <irrlicht.h>
#include "observator_3d.h"
#include "Obs.h"
#include "Socket.h"

using namespace	irr;

int	main(int ac, char **av)
{
  //  t_obs	obs;

  //  parse_args(ac, av, &obs);
  Obs		obs(ac, av);
  Socket	socket(obs.GetHost(), obs.GetPort());

  obs.Auth(socket);
  obs.DrawPlayer(2, 3, 1);
  obs.DrawAll();
  //  init_obs(&obs);
  //  draw_rock(&obs, 2, 2, 5);
  //  draw_rock(&obs, 4, 4, 5);
  //  draw_player(&obs, 1, 3, 0);
  //  draw_player(&obs, 4, 2, 2);
  //  while (DEVICE(obs.window->device)->run())
  //    {
  //msg_reception(obs);
  //      draw_all(&obs);
  //    }
  //  free_obs(&obs);
  return (0);
}
