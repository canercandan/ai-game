#include <irrlicht.h>
#include "observator.h"

using namespace irr;

int	main(int ac, char **av)
{
  t_obs	*obs;

  if (ac < 3)
    main_usage();
  obs = init_obs(av[1], av[2]);
  while(DEVICE(obs->window->device)->run())
    {
      //msg_reception(obs);
      draw_all(obs);
    }
  free_obs(obs);
  return (0);
}
