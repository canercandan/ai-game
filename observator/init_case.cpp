#include <irrlicht.h>
#include "observator.h"

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
}
