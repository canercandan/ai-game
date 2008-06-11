/*
** window.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:43:36 2008 jordan aubry
** Last update Wed Jun 11 21:04:20 2008 florent hochwelker
*/

#ifndef __WINDOW_H__
# define __WINDOW_H__

# include <iostream>
# include <vector>
# include <irrlicht.h>
# include "observator_3d.h"

class	Window
{
 public:
  Window();
  ~Window() {}

  void	InitWindow();
  inline irr::scene::ISceneManager*	GetScene() { return this->_scene; }
  inline irr::video::IVideoDriver*	GetDriver() { return this->_driver; }

 protected:
  irr::IrrlichtDevice*		_device;
  irr::video::IVideoDriver*	_driver;
  irr::scene::ISceneManager*	_scene;
  irr::gui::IGUIEnvironment*	_env;
  irr::scene::ICameraSceneNode*	_camera;
};

#endif
