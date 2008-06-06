//
// init_window.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:54 2008 majdi toumi
// Last update Thu Jun  5 18:08:37 2008 jordan aubry
//

#include <irrlicht.h>
#include <stdlib.h>
#include "observator_3d.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

t_window	*init_window()
{
  t_window	*w;

  w = (t_window *) malloc(sizeof(*w));
  w->device = createDevice(EDT_BURNINGSVIDEO,
                           dimension2d<s32>(WIN_WEIGHT, WIN_HEIGHT));
  w->driver = DEVICE(w->device)->getVideoDriver();
  w->smgr = DEVICE(w->device)->getSceneManager();
  w->env = DEVICE(w->device)->getGUIEnvironment();
  DRIVER(w->driver)->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, true);
  w->camera = MANAGER(w->smgr)->addCameraSceneNodeFPS(0, 100, CAMERA_SPEED);
  CAMERA(w->camera)->setPosition(vector3df(0, 0, 0));
  CAMERA(w->camera)->setTarget(vector3df(10, 0, 10));
  CAMERA(w->camera)->setFarValue(FAR_VALUE);
  DEVICE(w->device)->getCursorControl()->setVisible(false);
  DEVICE(w->device)->getFileSystem()->addZipFileArchive(OBS_PK3);
  DRIVER(w->driver)->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, false);
  /*
  MANAGER(w->smgr)->addSkyBoxSceneNode(DRIVER(w->driver)->getTexture(SKY_UP),
                              DRIVER(w->driver)->getTexture(SKY_DN),
                              DRIVER(w->driver)->getTexture(SKY_RT),
                              DRIVER(w->driver)->getTexture(SKY_LF),
                              DRIVER(w->driver)->getTexture(SKY_FT),
                              DRIVER(w->driver)->getTexture(SKY_BK));
  DRIVER(w->driver)->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, true);
  */
  return (w);
}
