#include <irrlicht.h>
#include "observator.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

void    init_map(t_window *w)
{
  w->map = w->smgr->addTerrainSceneNode("Map/case.bmp");
  w->map->setScale(core::vector3df(MAP_WEIGHT, 0, MAP_HEIGHT));
  w->map->setPosition(core::vector3df(0, 0, 0));
  w->map->setMaterialFlag(video::EMF_LIGHTING, false);
  w->map->setMaterialTexture(0, w->driver->getTexture("Map/case.jpg"));
  w->map->scaleTexture(1);
}
