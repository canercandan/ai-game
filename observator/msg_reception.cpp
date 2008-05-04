#include <irrlicht.h>
#include "observator.h"

void				msg_reception(t_obs *obs)
{
  IAnimatedMeshSceneNode	*invader;
  ISceneNodeAnimator		*anim;

  invader = obs->window->smgr->addAnimatedMeshSceneNode(obs->window->smgr->getMesh("models/perso.md2"));
  if (invader)
    {
      anim = obs->window->smgr->createFlyStraightAnimator(vector3df(1000, 24, 1000),
							  vector3df(10000, 24, 10000),
							  1000, true);
      invader->addAnimator(anim);
      anim->drop();
      invader->setFrameLoop(1, 300);
      invader->setAnimationSpeed(40);
      invader->setMaterialTexture(0, obs->window->driver->getTexture("models/sally.bmp"));
    }
}
