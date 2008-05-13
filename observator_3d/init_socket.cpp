//
// init_socket.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:46:19 2008 majdi toumi
// Last update Tue May 13 13:51:16 2008 jordan aubry
//

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include "observator_3d.h"

static void	error(t_obs *obs)
{
  write(1, SOCK_ERROR, sizeof(SOCK_ERROR));
  exit(-1);
}

void			init_socket(t_obs *obs)
{
  struct sockaddr_in	sin;
  struct hostent	*h;
  struct protoent	*pe;
  struct in_addr	in;

  pe = getprotobyname("tcp");
  if ((obs->sock = socket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    error(obs);
  sin.sin_family = AF_INET;
  if (!(h = gethostbyname(obs->host)))
    error(obs);
  bcopy(h->h_addr, &in, sizeof(in));
  sin.sin_port = htons(obs->port);
  sin.sin_addr.s_addr = inet_addr(inet_ntoa(in));
  if (connect(obs->sock, (struct sockaddr*)&sin, sizeof(sin)) < 0)
    error(obs);
}
