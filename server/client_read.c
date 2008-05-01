/*
** client_read.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:25:30 2008 caner candan
** Last update Thu May  1 15:34:52 2008 florent hochwelker
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "x.h"

void		client_read(t_info *info, int socket)
{
  t_client	*client;
  int		r;
  char		buf[BUF_SIZE + 1];
  char		buff_perso[BUF_SIZE + 1];
  char		*p;

  client = get_client_from_list(info->clients, socket);
  if ((r = (int)xrecv(client->socket, buf, BUF_SIZE, 0)) > 0)
    {
      buf[r] = '\0';
      strlcat(client->buf_read, buf, BUF_SIZE);
      while ((p = strstr(client->buf_read, "\n")))
	{
	  *p = 0;
	  strncpy(buff_perso, client->buf_read, BUF_SIZE - 1);
	  execute_action(buff_perso, client, info);
	  printf("%d: [%s]\n", client->socket, buf);
	  strncpy(client->buf_read, p + 1, BUF_SIZE);
	}
    }
  else
    client_disconnect(client, info);
}
