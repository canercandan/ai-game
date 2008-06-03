/*
** client_write.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 20:07:40 2008 caner candan
** Last update Mon Jun  2 19:28:59 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"
#include "x.h"

void		client_write(t_info *info, t_client *client)
{
  int		len;
  int		total_send;
  (void)info;

  debug("client_write()", -1);
  len = strlen(client->buf_write);
  while ((total_send = xsend(client->socket, client->buf_write, strlen(client->buf_write), 0) < len))
    len -= total_send;
  client->buf_write[0] = 0;
}
