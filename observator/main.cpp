#include <irrlicht.h>
#include "observator.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

int		main(int ac, char **av)
{
  t_window	w;

  if (ac < 3)
    exit(0);
  init_windows(&w);
  init_map(&w);
  w.sock = create_socket(av[1], av[2]);
  while(w.device->run())
  {
	w.driver->beginScene(true, true, 0);
	w.smgr->drawAll();
	w.env->drawAll();
	w.device->getGUIEnvironment()->drawAll();
	w.driver->endScene();
  }
  w.device->drop();
  return (0);
}
