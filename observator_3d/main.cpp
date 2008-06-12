//
// main.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:37:03 2008 majdi toumi
// Last update Thu Jun 12 11:48:29 2008 jordan aubry
//

#include <irrlicht.h>
#include "observator_3d.h"
#include "Obs.h"
#include "Socket.h"

using namespace	irr;

int	main(int ac, char **av)
{
  Obs		obs(ac, av);
  Socket	socket(obs.GetHost(), obs.GetPort());

  obs.Auth(socket);
  obs.DrawAll(socket);
  return (0);
}
