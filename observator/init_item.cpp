#include <irrlicht.h>
#include <stdlib.h>
#include "observator.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;

void		init_item(t_obs *obs)
{
  int		i;

  obs->item[0].img = DRIVER(obs->window->driver)->getTexture(ITEM_0);
  obs->item[1].img = DRIVER(obs->window->driver)->getTexture(ITEM_1);
  obs->item[2].img = DRIVER(obs->window->driver)->getTexture(ITEM_2);
  obs->item[3].img = DRIVER(obs->window->driver)->getTexture(ITEM_3);
  obs->item[4].img = DRIVER(obs->window->driver)->getTexture(ITEM_4);
  obs->item[5].img = DRIVER(obs->window->driver)->getTexture(ITEM_5);
  obs->item[6].img = DRIVER(obs->window->driver)->getTexture(ITEM_6);
  obs->item[7].img = DRIVER(obs->window->driver)->getTexture(ITEM_7);
  obs->item[8].img = DRIVER(obs->window->driver)->getTexture(ITEM_8);
  obs->item[9].img = DRIVER(obs->window->driver)->getTexture(ITEM_9);
  for (i = 0; i < NB_RESSOURCE; i++)
    {
      obs->item[i].x = i * 10;
      obs->item[i].y = 0;
      obs->item[i].z = 1;
    }
}
