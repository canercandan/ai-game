#include <irrlicht.h>
#include "observator.h"

int	main(int ac, char **av)
{
  t_obs	*obs;

  if (ac < 3)
    main_usage();
  obs = init_obs();
  init_socket(obs, av[1], av[2]);
  while(obs->window->device->run())
    draw_all(obs);
  free_obs(obs);
  return (0);
}
