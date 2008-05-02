/*
** add_server.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:40:48 2008 caner candan
** Last update Fri May  2 16:26:40 2008 florent hochwelker
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "server.h"
#include "x.h"

void			add_server(t_info *info)
{
  struct sockaddr_in	addr;
  struct protoent	*pe;
  t_client		*client;

  debug("add_server()", 2);
  pe = getprotobyname("tcp");
  client = xmalloc(sizeof(*client));
  client->socket = xsocket(PF_INET, SOCK_STREAM, pe->p_proto);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(info->port);
  addr.sin_addr.s_addr = INADDR_ANY;
  xbind(client->socket, (struct sockaddr *) &addr,
	(void *) sizeof(addr));
  xlisten(client->socket, MAX_LISTEN);
  client->status = ST_SERVER;
  client->fct_read = server_read;
  client->fct_write = server_write;
  client->buf_write[0] = 0;
  client->buf_read[0] = 0;
  push_list(&info->clients, (void *) client);
}
