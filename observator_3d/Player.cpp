//
// Player.cpp for Obs3D in /home/hochwe_f/zappy/observator_3d
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Fri Jun  6 19:55:06 2008 florent hochwelker
// Last update Fri Jun  6 20:00:16 2008 florent hochwelker
//

#include <irrlicht.h>
#include "Player.h"

Player::Player(int x, int y, irr::scene::IAnimatedMeshSceneNode* img) :
  _x(x), _y(y)
{
  _img = img;
}
