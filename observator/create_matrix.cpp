#include <irrlicht.h>
#include "observator.h"
#include "x.h"

void	create_matrix(t_matrix **m, int size_x, int size_y)
{
  int	i;
  int	j;
  int	k;

  m = xmalloc(sizeof(*m) * size_x);
  for (i = 0; i < size_x; i++)
    {
      m[i] = xmalloc(sizeof(**m) * size_y);
      for (j = 0; j < size_y; j++)
	{
	  m[i][j].move = 1;
	  m[i][j].level = 1;
	  for (k = 0; k < NB_RESSOURCE; k++)
	    m[i][j].item[k] = 0;
	}
    }
}
