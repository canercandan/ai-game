/*
** create_socket.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:32:18 2008 caner candan
** Last update Mon May 12 21:34:12 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <strings.h>
#include "observator_2d.h"
#include "x.h"

int			create_socket(t_info *info)
{
  struct sockaddr_in	addr;
  struct protoent	*pe;
  struct hostent	*h;
  struct in_addr	in;

  pe = getprotobyname("tcp");
  if ((info->socket = xsocket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    return (-1);
  addr.sin_family = AF_INET;
  printf("Resolving %s ...\n", info->host);
  if (!(h = gethostbyname(info->host)))
    return (-1);
  bcopy(h->h_addr, &in, sizeof(in));
  addr.sin_port = htons(info->port);
  addr.sin_addr.s_addr = inet_addr(inet_ntoa(in));
  if (xconnect(info->socket, (void *) &addr, (void *) sizeof(addr)) < 0)
    return (-1);
  return (0);
}
