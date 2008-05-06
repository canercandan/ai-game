#include <irrlicht.h>
#include "observator.h"

void		draw_rock(t_obs *obs, int x, int y)
{
  ISceneNode	*rock;

  rock = obs->window->smgr->addSphereSceneNode();
  if (rock)
    {
      rock->setScale(vector3df(1, 1, 1));
      rock->setPosition(vector3df(x, 0, y));
      rock->setMaterialFlag(EMF_LIGHTING, false);
    }
}
