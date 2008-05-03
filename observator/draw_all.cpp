#include <irrlicht.h>
#include "observator.h"

void	draw_all(t_obs *obs)
{
  obs->window->driver->beginScene(true, true, 0);
  obs->window->smgr->drawAll();
  obs->window->env->drawAll();
  obs->window->device->getGUIEnvironment()->drawAll();
  obs->window->driver->endScene();
}
