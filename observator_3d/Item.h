/*
** item.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:50:13 2008 jordan aubry
** Last update Fri Jun  6 19:07:24 2008 florent hochwelker
*/

#ifndef __ITEM_H__
# define __ITEM_H__

# include <iostream>
# include <irrlicht.h>

class	Item
{
 public:
  Item();
  ~Item() {}

 private:
  int				_qte;
  irr::video::IVideoDriver*	_img;
  

};

#endif
