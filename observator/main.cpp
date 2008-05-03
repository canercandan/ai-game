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
  create_socket(w.sock, av[1], av[2]);
  init_windows(&w);
  init_map(&w);
  while(w.device->run())
    draw_all(&w);
  free_and_exit(&w);
  return (0);
}
