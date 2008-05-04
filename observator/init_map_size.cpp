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
  buf[i] = '\0';
  printf("reception : %s\n", buf);
  printf("envoie du magic\n");
  send(obs->sock, OBS_MAGIC, sizeof(OBS_MAGIC), 0);
  i = recv(obs->sock, buf, 32, 0);
  buf[i] = '\0';
  printf("reception : %s\n", buf);
  obs->x = extract_num(buf, 1);
  obs->y = extract_num(buf, 2);
  printf("taille map : %d x %d\n", obs->x, obs->y);
}
