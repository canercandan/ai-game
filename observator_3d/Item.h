/*
** item.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:50:13 2008 jordan aubry
** Last update Sat Jun  7 19:45:32 2008 florent hochwelker
*/

#ifndef __ITEM_H__
# define __ITEM_H__

# include <iostream>
# include <irrlicht.h>

class	Item
{
 public:
 Item() : _qte(0) { _img = NULL; }
  ~Item() {}
  
  int				_qte;
  irr::scene::ISceneNode*	_img;
};

#endif
