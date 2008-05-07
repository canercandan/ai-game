#include <irrlicht.h>
#include "observator.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

void	draw_all(t_obs *obs)
{
  DRIVER(obs->window->driver)->beginScene(true, true, 0);
  MANAGER(obs->window->smgr)->drawAll();
  ENV(obs->window->env)->drawAll();
  DEVICE(obs->window->device)->getGUIEnvironment()->drawAll();
  DRIVER(obs->window->driver)->endScene();
}
