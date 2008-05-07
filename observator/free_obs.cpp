#include <stdlib.h>
#include "observator.h"

void	free_obs(t_obs *obs)
{
  int	i;

  for (i = 0; i < obs->x; i++)
    free(obs->matrix[i]);
  free(obs->matrix);
  free(obs->window);
  free(obs->item);
  free(obs);
}
