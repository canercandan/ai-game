#include <irrlicht.h>
#include "observator.h"
#include "x.h"

t_window	*init_window()
{
  t_window	*w;

  w = (t_window *) xmalloc(sizeof(*w));
  w->device = createDevice(EDT_BURNINGSVIDEO,
                           dimension2d<s32>(WIN_WEIGHT, WIN_HEIGHT));
  w->driver = w->device->getVideoDriver();
  w->smgr = w->device->getSceneManager();
  w->env = w->device->getGUIEnvironment();
  w->driver->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, true);
  w->camera = w->smgr->addCameraSceneNodeFPS(0, 100, 1000);
  w->camera->setPosition(vector3df(0, 100, 0));
  w->camera->setTarget(vector3df(100, 100, 100));
  w->camera->setFarValue(FAR_VALUE);
  w->device->getCursorControl()->setVisible(false);
  w->driver->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, false);
  w->smgr->addSkyBoxSceneNode(w->driver->getTexture(SKY_UP),
                              w->driver->getTexture(SKY_DN),
                              w->driver->getTexture(SKY_RT),
                              w->driver->getTexture(SKY_LF),
                              w->driver->getTexture(SKY_FT),
                              w->driver->getTexture(SKY_BK));
  w->driver->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, true);
  return (w);
}
