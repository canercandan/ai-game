#include <irrlicht.h>
#include "observator.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

void    init_windows(t_window *w)
{
  w->device = createDevice(EDT_BURNINGSVIDEO,
                           dimension2d<s32>(WIN_WEIGHT, WIN_HEIGHT));
  w->driver = w->device->getVideoDriver();
  w->smgr = w->device->getSceneManager();
  w->env = w->device->getGUIEnvironment();
  w->driver->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, true);
  w->camera = w->smgr->addCameraSceneNodeFPS(0, 100, 1000);
  w->camera->setPosition(core::vector3df(0, 100, 0));
  w->camera->setTarget(core::vector3df(100, 100, 100));
  w->camera->setFarValue(100000);
  w->device->getCursorControl()->setVisible(false);
  //w->driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);
  w->driver->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, false);
  w->smgr->addSkyBoxSceneNode(w->driver->getTexture(CUBE_SKY_UP),
                              w->driver->getTexture(CUBE_SKY_DN),
                              w->driver->getTexture(CUBE_SKY_RT),
                              w->driver->getTexture(CUBE_SKY_LF),
                              w->driver->getTexture(CUBE_SKY_FT),
                              w->driver->getTexture(CUBE_SKY_BK));
  w->driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, true);
}
