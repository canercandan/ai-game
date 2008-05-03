#include <irrlicht.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "observator.h"

void	init_map_size(t_obs *obs)
{
  char	buf[32];
  int	i;

  i = recv(obs->sock, buf, 32, 0);
  for (i = 0; buf[i] != '\n'; i++)
    write(1, &buf[i], 1);
  send(obs->sock, OBS_MAGIC, sizeof(OBS_MAGIC), 0);
  recv(obs->sock, buf, 32, 0);
  obs->x = extract_num(buf, 1);
  obs->y = extract_num(buf, 2);
}
