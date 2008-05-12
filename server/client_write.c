/*
** client_write.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 20:07:40 2008 caner candan
** Last update Mon May 12 19:52:33 2008 majdi toumi
*/

#include <string.h>
#include "server.h"
#include "x.h"

void		client_write(t_info *info, t_client *client)
{
  (void) info;
  debug("client_write()", -1);
  xsend(client->socket, client->buf_write, strlen(client->buf_write), 0);
  client->buf_write[0] = 0;
}
