/*
** client_write.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 20:07:40 2008 caner candan
** Last update Thu Jul 10 08:34:17 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "x.h"

void	client_write(t_info *info, t_client *client)
{
  int	len;
  int	total_send;

  (void)info;
  len = strlen(client->buf_write);
  while ((total_send = xsend(client->socket, client->buf_write, len, 0)) < len)
    { 
      memmove(client->buf_write, client->buf_write + total_send, len - total_send);
      len -= total_send;
    }
  client->buf_write[0] = 0;
}
