#include <irrlicht.h>
#include "observator.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

void	draw_all(t_window *w)
{
  w->driver->beginScene(true, true, 0);
  w->smgr->drawAll();
  w->env->drawAll();
  w->device->getGUIEnvironment()->drawAll();
  w->driver->endScene();
}
