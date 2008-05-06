#include <irrlicht.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "observator.h"
#include "common.h"

void	init_map_size(t_obs *obs)
{
  char	buf[32];
  int	i;

  printf("Map size :\n");
  i = recv(obs->sock, buf, 32, 0);
  send(obs->sock, MAGIC_OBS, strlen(MAGIC_OBS), 0);
  send(obs->sock, "\n", 1, 0);
  i = recv(obs->sock, buf, 32, 0);
  buf[i] = '\0';
  printf(" %s", buf);
  obs->x = extract_num(buf, 1);
  obs->y = extract_num(buf, 2);
  printf("-> %d x %d\n", obs->x, obs->y);
}
