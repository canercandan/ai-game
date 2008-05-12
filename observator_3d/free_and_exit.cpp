//
// free_and_exit.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:28 2008 majdi toumi
// Last update Mon May 12 19:21:27 2008 caner candan
//

#include <irrlicht.h>
#include "observator_3d.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

void	free_and_exit(t_window *w)
{
  w->device->drop();
  exit(0);
}
