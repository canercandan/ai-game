/*
** new_connection.c for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 18:46:06 2008 florent hochwelker
** Last update Thu Apr 10 19:13:31 2008 florent hochwelker
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int			new_connection(char *team_name, char *host, int port)
{
  int		 	s;
  struct sockaddr_in	sin;
  struct protoent	*pe;
  struct hostent	*h;
  struct in_addr	in;

  pe = getprotobyname("tcp");
  if ((s = socket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
    perror("socket");
  sin.sin_family = AF_INET;
  printf("Resolving %s ... ", argv[1]);
  if (!(h = gethostbyname(argv[1])))
    perror("resolv");
  bcopy(h->h_addr, &in, sizeof(in));
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(inet_ntoa(in));
  if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    perror("n00b");
  return (s);
}
