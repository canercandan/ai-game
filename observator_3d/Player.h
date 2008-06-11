/*
** player.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:53:08 2008 jordan aubry
** Last update Wed Jun 11 21:08:37 2008 florent hochwelker
*/

#ifndef __PLAYER_H__
# define __PLAYER_H__

# include <vector>
# include <iostream>
# include <string>
# include <irrlicht.h>
# include "observator_3d.h"
# include "common.h"

class	Player
{
 public:
 Player() : _inventory(NB_RESSOURCE, 0) {}
  ~Player() {}

  inline int		GetX() const { return this->_x; }
  inline int		GetY() const { return this->_y; }

  int					_id;
  std::string				_team;
  int					_id_team;
  int					_lvl;
  int					_x;
  int					_y;
  int					_z;
  std::vector<int>			_inventory;
  irr::scene::IAnimatedMeshSceneNode*	_img;
  irr::scene::ISceneNode*		_egg;
};

#endif
