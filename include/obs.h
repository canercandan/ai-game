/*
** obs.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 14:11:25 2008 jordan aubry
** Last update Tue Jun  3 20:05:44 2008 jordan aubry
*/

#ifndef __OBS_H__
# define __OBS_H__

# include <iostream>
# include <vector>
# include "matrix.h"
# include "player.h"
# include "window.h"
# include "item.h"

class	Obs : public Window
{
 private:
  std::string	_host;
  int		_port;
  int		_sock;
  int		_sizex;
  int		_sizey;
  vector<vector<Matrix>>	_matrix;
  vector<Player>		_player;
  vector<Window>		_window;
  vector<Item>			_item;

 public:
  Obs();
  ~Obs();
};

#endif
