#include <irrlicht.h>
#include "observator.h"

int		main(int ac, char **av)
{
  t_window	w;
  t_matrix	**m;

  if (ac < 3)
    exit(0);
  create_socket(w.sock, av[1], av[2]);
  init_windows(&w);
  init_map(&w);
  init_matrix(&w, m);
  while(w.device->run())
    {
      //receve_all();
      //modify_all(&w);
      draw_all(&w);
    }
  free_and_exit(&w);
  return (0);
}
