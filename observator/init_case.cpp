#include <irrlicht.h>
#include "observator.h"

void		init_case(t_obs *obs)
{
  ISceneNode	*node;

  node = obs->window->smgr->addCubeSceneNode();
  if (node)
    {
      node->setScale(vector3df((obs->x * 10), 1, (obs->y * 10)));
      node->setMaterialTexture(0, obs->window->driver->getTexture("textures/case.bmp"));
      node->setMaterialFlag(EMF_LIGHTING, false);
      node->setPosition(vector3df(0, -1, 0));
    }
}
