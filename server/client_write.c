/*
** client_write.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 20:07:40 2008 caner candan
** Last update Wed Apr 30 21:01:20 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "x.h"

void		client_write(t_info *info, int socket)
{
  t_client	*client;

  debug("client_write()", -1);
  client = get_client_from_list(info->clients, socket);
  xsend(socket, client->buf_write, strlen(client->buf_write), 0);
  client->buf_write[0] = 0;
}
