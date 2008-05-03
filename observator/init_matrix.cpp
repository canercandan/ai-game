#include <irrlicht.h>
#include "observator.h"
#include "x.h"

t_matrix	**init_matrix(t_obs *obs)
{
  t_matrix	**m;
  int		i;
  int		j;
  int		k;

  m = (t_matrix **) xmalloc(sizeof(*m) * obs->x);
  for (i = 0; i < obs->x; i++)
    {
      m[i] = (t_matrix *) xmalloc(sizeof(**m) * obs->y);
      for (j = 0; j < obs->y; j++)
	{
	  m[i][j].move = 1;
	  m[i][j].level = 1;
	  for (k = 0; k < NB_RESSOURCE; k++)
	    m[i][j].item[k] = 0;
	}
    }
  return (m);
}
