#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <irrlicht.h>
#include "observator.h"

void			create_socket(int sock, char *name, char *port)
{
  struct sockaddr_in	sin;
  struct hostent	*h;
  struct protoent	*pe;
  struct in_addr	in;

  pe = getprotobyname("tcp");
  if ((sock = socket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    {
      write(1, SOCK_ERROR, sizeof(SOCK_ERROR));
      exit(0);
    }
  sin.sin_family = AF_INET;
  if (!(h = gethostbyname(name)))
    {
      write(1, SOCK_ERROR, sizeof(SOCK_ERROR));
      exit(0);
    }
  bcopy(h->h_addr, &in, sizeof(in));
  sin.sin_port = htons(atoi(port));
  sin.sin_addr.s_addr = inet_addr(inet_ntoa(in));
  if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0)
    {
      write(1, SOCK_ERROR, sizeof(SOCK_ERROR));
      exit(0);
    }
}
