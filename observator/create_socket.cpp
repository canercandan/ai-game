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
  struct hostent	*host;

  if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
      write(1, SOCK_ERROR, sizeof(SOCK_ERROR));
      exit(0);
    }
  host = gethostbyname(name);
  memcpy(&sin.sin_addr.s_addr, host->h_addr, sizeof(host->h_addr));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(atoi(port));
  if ((connect(sock, (struct sockaddr*)&sin, sizeof(sin))) < 0)
    {
      write(1, SOCK_ERROR, sizeof(SOCK_ERROR));
      exit(0);
    }
}
