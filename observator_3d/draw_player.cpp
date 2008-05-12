//
// draw_player.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:11 2008 majdi toumi
// Last update Mon May 12 13:48:11 2008 majdi toumi
//

#include <irrlicht.h>
#include "observator.h"
#include "common.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;

void				draw_player(t_obs *obs, int x, int y, int z)
{
  IAnimatedMeshSceneNode	*node;
  void				*p;

  p = obs->window->smgr;
  node = MANAGER(p)->addAnimatedMeshSceneNode(MANAGER(p)->getMesh(INVADER));
  if (node)
    {
      node->setFrameLoop(1, 1);
      node->setAnimationSpeed(0);
      node->setMaterialFlag(EMF_LIGHTING, false);
      node->setPosition(vector3df(X(x), 0, Y(y)));
      p = obs->window->driver;
      node->setMaterialTexture(0, DRIVER(p)->getTexture(SKIN_1));
      if (z == NORTH)
	z = 180;
      else if (z == EAST)
	z = 270;
      else if (z == WEST)
	z = 90;
      else
	z = 0;
      node->setRotation(vector3df(0, z, 0));
    }
}
