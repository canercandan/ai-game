/*
** player.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:53:08 2008 jordan aubry
** Last update Tue Jun 17 23:23:26 2008 jordan aubry
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
  Player();
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
  float					_anim;
  float					_anim2;
  int					_life;
  std::vector<int>			_inventory;
  std::vector< std::vector<std::string> >			_skin;
  irr::scene::IAnimatedMeshSceneNode*	_img;
  irr::scene::ISceneNode*		_egg;
  irr::scene::ISceneNode*		_light;
  irr::scene::IParticleSystemSceneNode*	_ps;
};

#endif
