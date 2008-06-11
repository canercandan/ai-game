//
// Window.cpp for Obs3D in /home/hochwe_f/zappy/observator_3d
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Fri Jun  6 18:04:30 2008 florent hochwelker
// Last update Tue Jun 10 15:09:50 2008 florent hochwelker
//

#include <irrlicht.h>
#include "observator_3d.h"
#include "Window.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

Window::Window()
{
  _device = createDevice(EDT_BURNINGSVIDEO,
			 dimension2d<s32>(WIN_WEIGHT, WIN_HEIGHT));
  _driver = _device->getVideoDriver();
  _scene = _device->getSceneManager();
  _env = _device->getGUIEnvironment();
  _driver->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, true);
  //  _camera = _scene->addCameraSceneNodeFPS(0, 100, CAMERA_SPEED);

  _camera = _scene->addCameraSceneNodeMaya(0);
  _camera->setPosition(vector3df(0, 0, 0));
  _camera->setTarget(vector3df(10, 0, 10));
  _camera->setFarValue(FAR_VALUE);
  _device->getFileSystem()->addZipFileArchive(OBS_PK3);
  _driver->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, false);
  _scene->addSkyBoxSceneNode(_driver->getTexture(SKY_UP),
                             _driver->getTexture(SKY_DN),
			     _driver->getTexture(SKY_RT),
			     _driver->getTexture(SKY_LF),
			     _driver->getTexture(SKY_FT),
			     _driver->getTexture(SKY_BK));
  _driver->setTextureCreationFlag(ETCF_OPTIMIZED_FOR_SPEED, true);
}
