#include <irrlicht.h>
#include "observator.h"
#include "x.h"

t_obs		*init_obs()
{
  t_obs		*obs;

  obs = (t_obs *) xmalloc(sizeof(*obs));
  obs->window = init_window();
  init_map_size(obs);
  obs->matrix = init_matrix(obs);
  init_case(obs);
  return (obs);
}
