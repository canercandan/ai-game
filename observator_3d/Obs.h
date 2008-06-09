/*
** obs.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 14:11:25 2008 jordan aubry
** Last update Mon Jun  9 18:36:00 2008 florent hochwelker
*/

#ifndef __OBS_H__
# define __OBS_H__

# include <irrlicht.h>
# include <iostream>
# include <vector>
# include <map>
# include <string>
# include "common.h"
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
  void		DrawAll(Socket& socket);

  inline int		GetX() const { return this->_x; }
  inline int		GetY() const { return this->_y; }
  inline std::string	GetHost() const { return this->_host; }
  inline int		GetPort() const { return this->_port; }

 private:
  int					_x;
  int					_y;
  std::map<int, Player*>		_player;
  std::vector< std::vector< std::vector<Item> > >	_item;
  int					_t;
  std::string				_host;
  int					_port;
  irr::video::ITexture*			_texture[NB_RESSOURCE];

  void					DrawPlate();
  void					DrawItem(int x, int y, int type);
  void					DeleteItem(int x, int y, int type);
  void					DrawPlayer(Player* player);
  void					ExecuteAction(std::string& line);
};

#endif
