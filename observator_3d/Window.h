/*
** window.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:43:36 2008 jordan aubry
** Last update Tue Jun  3 20:19:17 2008 jordan aubry
*/

#ifndef __WINDOW_H__
# define __WINDOW_H__

# include <iostream>
# include <vector>
# include <irrlicht.h>
# include "observateur_3d.h"

class	Window
{
 public:
  Window();
  ~Window();

 protected:
  IrrlichtDevice*       _device;
  IVideoDriver*         _driver;
  ISceneManager*        _scene;
  IGUIEnvironement*     _env;
  ICameraSceneNore*     _camera;
};

#endif
