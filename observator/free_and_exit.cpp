#include <irrlicht.h>
#include "observator.h"

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

void	free_and_exit(t_window *w)
{
  w->device->drop();
  exit(0);
}
