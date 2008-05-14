/*
** add_server.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:40:48 2008 caner candan
** Last update Wed May 14 11:48:23 2008 majdi
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "server.h"
#include "common.h"
#include "x.h"

void			add_server(t_info *info)
{
  struct sockaddr_in	addr;
  struct protoent	*pe;
  t_client		*client;

  pe = getprotobyname(TCP);
  client = xmalloc(sizeof(*client));
  client->socket = xsocket(PF_INET, SOCK_STREAM, pe->p_proto);
  client->id = -1;
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
