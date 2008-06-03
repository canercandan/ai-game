/*
** item.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:50:13 2008 jordan aubry
** Last update Tue Jun  3 19:59:02 2008 jordan aubry
*/

#ifndef __ITEM_H__
# define __ITEM_H__

# include <iostream>
# include <irrlicht.h>

class	Item
{
 private:
  IVideoDriver*		img;
  int			x;
  int			y;
  int			z;

 public:
  Item();
  ~Item();
};

#endif
