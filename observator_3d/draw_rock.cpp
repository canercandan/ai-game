//
// draw_rock.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:17 2008 majdi toumi
// Last update Wed May 14 14:03:19 2008 jordan aubry
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
      rock = setScale(vector3df(1, 1, 1));
      rock = setPosition(vector3df(X(x), obs->item[type].z, Y(y)));
      rock = setMaterialFlag(EMF_LIGHTING, false);
      rock = setMaterialTexture(0, TEXTURE(obs->item[type].img));
    }
  if (obs->matrix[x][y].move == 1)
    {
      obs->matrix[x][y].item[type] += 1;
      if (obs->matrix[x][y].item[type] > 1)
	rock->~ISceneNode();
      else
	obs->matrix[x][y].rock[type] = rock;
      obs->matrix[x][y].item[type] += 1;
    }
}
