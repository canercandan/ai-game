#include <irrlicht.h>
#include <unistd.h>
#include <stdlib.h>
#include "observator.h"
#include "x.h"

void	init_matrix(t_window *w, t_matrix **m)
{
  char	buf[64];
  int	size_x;
  int	size_y;
  int	i;

  i = xrecv(w->sock, buf, 64, 0);
  for (i = 0; buf[i] != '\n'; i++)
    write(1, &buf[i], 1);
  xsend(w->sock, OBS_MAGIC, sizeof(OBS_MAGIC), 0);
  i = xrecv(w->sock, buf, 64, 0);
  size_x = extract_num(buf, 1);
  size_y = extract_num(buf, 2);
  create_matrix(m, size_x, size_y);
  create_case(w, size_x, size_y);
}
