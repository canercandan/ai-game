/*
** matrix.h for zappy in /home/aubry_j/zappy
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Tue Jun  3 19:26:48 2008 jordan aubry
** Last update Tue Jun  3 20:20:30 2008 jordan aubry
*/

#ifndef __MATRIX_H__
# define __MATRIX_H__

# include <iostream>
# include <vector>
# include <irrlicht.h>
# include "observator_3d.h"

class	Matrix
{
 public:
  Matrix();
  ~Matrix();

 private:
  std::vector<int>           _item(NB_RESSOURCE, 0);
  std::vector<ISceneNode*>   _rock;
  int		             _move;
};

#endif
