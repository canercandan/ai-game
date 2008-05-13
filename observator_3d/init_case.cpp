//
// init_case.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:36 2008 majdi toumi
// Last update Tue May 13 14:37:14 2008 jordan aubry
//

#include <irrlicht.h>
#include "observator_3d.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

void		init_case(t_obs *obs)
{
  ISceneNode	*node;
  int		x;
  int		y;

  for (x = 0; x < (obs->x); x++)
    {
      for (y = 0; y < (obs->y); y++)
	{
	  node = MANAGER(obs->window->smgr)->addCubeSceneNode();
	  node->setScale(vector3df(10, 1, 10));
	  node->setMaterialFlag(EMF_LIGHTING, false);
	  node->setMaterialTexture(0, DRIVER(obs->window->driver)->getTexture(MAP_CASE));
	  node->setPosition(vector3df(CASEX(x), -29, CASEY(y)));
	}
    }
  /*
  x = obs->x * 10;
  y = obs->y * 10;
  node = MANAGER(obs->window->smgr)->addCubeSceneNode();
  if (node)
    {
      node->setScale(vector3df(x, 1, y));
      node->setMaterialTexture(0, DRIVER(obs->window->driver)->getTexture(MAP_CASE));
      node->setMaterialFlag(EMF_LIGHTING, false);
      node->setPosition(vector3df(0, -29, 0));
    }
  */
}
