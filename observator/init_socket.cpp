#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <irrlicht.h>
#include "observator.h"

void			init_socket(t_obs *obs, char *name, char *port)
{
  struct sockaddr_in	sin;
  struct hostent	*h;
  struct protoent	*pe;
  struct in_addr	in;

  pe = getprotobyname("tcp");
  if ((obs->sock = socket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    {
      write(1, SOCK_ERROR, sizeof(SOCK_ERROR));
      free_obs(obs);
    }
  sin.sin_family = AF_INET;
  if (!(h = gethostbyname(name)))
    {
      write(1, SOCK_ERROR, sizeof(SOCK_ERROR));
      free_obs(obs);
    }
  bcopy(h->h_addr, &in, sizeof(in));
  sin.sin_port = htons(atoi(port));
  sin.sin_addr.s_addr = inet_addr(inet_ntoa(in));
  if (connect(obs->sock, (struct sockaddr*)&sin, sizeof(sin)) < 0)
    {
      write(1, SOCK_ERROR, sizeof(SOCK_ERROR));
      free_obs(obs);
    }
}
