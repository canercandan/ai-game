/*
** obs.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 14:11:25 2008 jordan aubry
** Last update Sat Jun  7 16:05:50 2008 florent hochwelker
*/

#ifndef __OBS_H__
# define __OBS_H__

# include <iostream>
# include <vector>
# include <string>
# include "Player.h"
# include "Window.h"
# include "Item.h"
# include "Socket.h"

class	Obs : public Window
{
 public:
  Obs(int, char**);
  ~Obs() {}

  void		Auth(Socket& socket);
  void		DrawAll();

  inline int		GetX() const { return this->_x; }
  inline int		GetY() const { return this->_y; }
  inline std::string	GetHost() const { return this->_host; }
  inline int		GetPort() const { return this->_port; }

  void					DrawPlayer(int x, int y, int z);
  void					DrawItem(int x, int y, int type);


 private:
  int					_x;
  int					_y;
  std::vector<Player*>			_player;
  std::vector< std::vector<Item> >	_item;
  int					_t;
  std::string				_host;
  int					_port;

  void					DrawPlate();
  void					DrawPlayer();
};

#endif
