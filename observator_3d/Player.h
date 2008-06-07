/*
** player.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:53:08 2008 jordan aubry
** Last update Sat Jun  7 13:24:20 2008 florent hochwelker
*/

#ifndef __PLAYER_H__
# define __PLAYER_H__

# include <vector>
# include <iostream>
# include <string>
# include <irrlicht.h>
# include "observator_3d.h"

class	Player
{
 public:
  Player(int x, int y, irr::scene::IAnimatedMeshSceneNode* img);
  ~Player() {}

  inline int		GetX() const { return this->_x; }
  inline int		GetY() const { return this->_y; }

 private:
  int					_id;
  std::vector<int>			_inventory;
  std::string				_team;
  int					_id_team;
  int					_x;
  int					_y;
  int					_lvl;
  irr::scene::IAnimatedMeshSceneNode*	_img;
};

#endif
