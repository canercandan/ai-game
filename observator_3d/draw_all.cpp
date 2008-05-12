//
// draw_all.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:06 2008 majdi toumi
// Last update Mon May 12 13:48:07 2008 majdi toumi
//

#include <irrlicht.h>
#include "observator.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

void	draw_all(t_obs *obs)
{
  DRIVER(obs->window->driver)->beginScene(true, true, 0);
  MANAGER(obs->window->smgr)->drawAll();
  ENV(obs->window->env)->drawAll();
  DEVICE(obs->window->device)->getGUIEnvironment()->drawAll();
  DRIVER(obs->window->driver)->endScene();
}
