//
// rm_rock.cpp for zappy in /home/aubry_j/zappy/observator_3d
// 
// Made by jordan aubry
// Login   <aubry_j@epitech.net>
// 
// Started on  Tue May 13 22:26:27 2008 jordan aubry
// Last update Wed May 14 11:48:45 2008 jordan aubry
//

#include <irrlicht.h>
#include "observator_3d.h"

using namespace irr;
using namespace video;
using namespace scene;

void	rm_rock(t_obs *obs, int x, int y, int type)
{
  if (obs->matrix[x][y].item[type] > 0)
    {
      obs->matrix[x][y].item[type] -= 1;
      if (obs->matrix[x][y].item[type] == 0)
	ISN(obs->matrix[x][y].rock[type])->~ISceneNode();
    }
}
