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
  w->driver->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_QUALITY, true);
  w->camera = w->smgr->addCameraSceneNodeFPS(0, 100, 1000);
  w->camera->setPosition(core::vector3df(0, 100, 0));
  w->camera->setTarget(core::vector3df(100, 100, 100));
  w->camera->setFarValue(100000);
  w->device->getCursorControl()->setVisible(false);
  w->driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);
  w->smgr->addSkyBoxSceneNode(w->driver->getTexture("Cube/up.tga"),
                              w->driver->getTexture("Cube/dn.tga"),
                              w->driver->getTexture("Cube/rt.tga"),
                              w->driver->getTexture("Cube/lf.tga"),
                              w->driver->getTexture("Cube/ft.tga"),
                              w->driver->getTexture("Cube/bk.tga"));
  w->driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, true);
}