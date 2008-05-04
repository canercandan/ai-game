#include <irrlicht.h>
#include "observator.h"

void		init_case(t_obs *obs)
{
  IAnimatedMesh *map;
  ISceneNode	*node;
  int		i;
  int		j;

  map = obs->window->smgr->getMesh(MAP_CASE_BSP);
  if (map)
    {
      for (i = 0; i < obs->x; i++)
	{
	  for (j = 0; j < obs->y; j++)
	    {
	      node = obs->window->smgr->addOctTreeSceneNode(map->getMesh(0));
	      node->setPosition(vector3df((i * OBS_CASE), 0, (j * OBS_CASE)));
	    }
	}
    }
}
