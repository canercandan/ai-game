/*
** new_connection.c for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 18:46:06 2008 florent hochwelker
** Last update Wed May  7 23:31:35 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <strings.h>
#include "client.h"
#include "x.h"

int			new_connection(t_info *info)
{
  struct sockaddr_in	sin;
  struct protoent	*pe;
  struct hostent	*h;
  struct in_addr	in;

  pe = getprotobyname("tcp");
  if ((info->socket = xsocket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    return (-1);
  sin.sin_family = AF_INET;
  printf("Resolving %s ...\n", info->host);
  if (!(h = gethostbyname(info->host)))
    return (-1);
  bcopy(h->h_addr, &in, sizeof(in));
  sin.sin_port = htons(info->port);
  sin.sin_addr.s_addr = inet_addr(inet_ntoa(in));
  if (xconnect(info->socket, (void *) &sin, (void *) sizeof(sin)) < 0)
    return (-1);
  return (0);
}
