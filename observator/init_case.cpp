#include <irrlicht.h>
#include "observator.h"

void		init_case(t_obs *obs)
{
  IAnimatedMesh *map;
  ISceneNode	*node;
  int		i;
  int		j;

  //obs->window->device->getFileSystem()->addZipFileArchive("map.pk3");
  map = obs->window->smgr->getMesh("maps/case.bsp");
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
