#include <stdlib.h>
#include "observator.h"

t_obs		*init_obs(char *host, char *port)
{
  t_obs		*obs;

  obs = (t_obs *) malloc(sizeof(*obs));
  init_socket(obs, host, port);
  obs->window = init_window();
  init_map_size(obs);
  obs->matrix = init_matrix(obs);
  init_item(obs);
  init_case(obs);
  return (obs);
}
