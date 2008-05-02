#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <irrlicht.h>
#include "observator.h"

int			create_socket(char *name, char *port)
{
  struct sockaddr_in	s;
  struct hostent	*host;
  int			len;
  int			sock;

  sock = socket(PF_INET, SOCK_STREAM, 0);
  s.sin_family = AF_INET;
  s.sin_port = htons(atoi(port));
  host = gethostbyname(name);
  memcpy(&s.sin_addr, host->h_addr_list[0], sizeof(host->h_addr));
  len = sizeof(struct sockaddr_in);
  if ((connect(sock, (struct sockaddr*)&s, len)) == 0)
    return (sock);
  else
    return (0);
}
