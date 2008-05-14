//
// draw_rock.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:17 2008 majdi toumi
// Last update Wed May 14 11:58:45 2008 jordan aubry
//

#include <irrlicht.h>
#include "observator_3d.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace core;

void		draw_rock(t_obs *obs, int x, int y, int type)
{
  obs->matrix[x][y].rock[type] =
    MANAGER(obs->window->smgr)->addSphereSceneNode();
  ISN(obs->matrix[x][y].rock[type])->
    setScale(vector3df(1, 1, 1));
  ISN(obs->matrix[x][y].rock[type])->
    setPosition(vector3df(X(x), obs->item[type].z, Y(y)));
  ISN(obs->matrix[x][y].rock[type])->
    setMaterialFlag(EMF_LIGHTING, false);
  ISN(obs->matrix[x][y].rock[type])->
    setMaterialTexture(0, TEXTURE(obs->item[type].img));
  if (obs->matrix[x][y].move == 1)
    {
      if (obs->matrix[x][y].item[type] > 0)
	ISN(obs->matrix[x][y].rock[type])->~ISceneNode();
      obs->matrix[x][y].item[type] += 1;
    }
}
