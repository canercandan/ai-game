/*
** player.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:53:08 2008 jordan aubry
** Last update Tue Jun  3 19:59:20 2008 jordan aubry
*/

#ifndef __PLAYER_H__
# define __PLAYER_H__

# include <vector>
# include <iostream>
# include <string>
# include "observator_3d.h"

class	Player
{
 private:
  std::string	_team;
  int		_id;
  int		_x;
  int		_y;
  int		_casex;
  int		_casey;
  int		_life;
  vector<int>	_inventory (NB_RESSOURCE, 0);

 public:
  Player();
  ~Player();
};

#endif
