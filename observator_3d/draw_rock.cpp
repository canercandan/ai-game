//
// draw_rock.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:17 2008 majdi toumi
// Last update Mon May 12 19:21:16 2008 caner candan
//

#include <irrlicht.h>
#include "observator_3d.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace core;

void		draw_rock(t_obs *obs, int x, int y, int type)
{
  ISceneNode	*rock;

  rock = MANAGER(obs->window->smgr)->addSphereSceneNode();
  if (rock)
    {
      rock->setScale(vector3df(1, 1, 1));
      rock->setPosition(vector3df(x, obs->item[type].z, y));
      rock->setMaterialFlag(EMF_LIGHTING, false);
      rock->setMaterialTexture(0, TEXTURE(obs->item[type].img));
    }
}
