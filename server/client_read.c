/*
** client_read.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:25:30 2008 caner candan
** Last update Wed Apr 30 17:50:53 2008 caner candan
*/

#include <stdio.h>
#include "server.h"
#include "x.h"
#include "server.h"

void	client_read(t_info *info, int socket)
{
  t_cli	*cli;
  int	r;
  char	buf[4096];

  debug("client_read()", 3);
  cli = get_client_from_list(info->clients, socket);
  if ((r = (int) xrecv(cli->socket, buf, sizeof(buf), 0)) > 0)
    {
      buf[r] = '\0';
      printf("%d: %s\n", cli->socket, buf);
    }
  else
    {
      printf("%d: Connection closed\n", cli->socket);
      xclose(cli->socket);
      cli->fd_type = FD_FREE;
      pop_client_from_list(&info->clients, socket);
    }
}
