/*
** server_get.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 10:20:01 2008 caner candan
** Last update Wed Apr 30 14:31:53 2008 caner candan
*/

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include "server.h"

static void	get_set_fd(t_list *t, fd_set *fd_read,
			   fd_set *fd_write, int *fd_max)
{
  t_cli		*cli;

  debug("get_set_fd()");
  fd_max = 0;
  while (t)
    {
      cli = t->data;
      if (cli->fd_type != FD_FREE)
	{
	  FD_SET(cli->socket, fd_read);
	  FD_SET(cli->socket, fd_write);
	  *fd_max = cli->socket;
	}
      t = t->next;
    }
}

static void	get_isset_fd(t_info *info, fd_set *fd_read,
			     fd_set *fd_write)
{
  t_list	*t;
  t_cli		*cli;

  debug("get_isset_fd()");
  t = info->clients;
  while (t)
    {
      cli = t->data;
      if (FD_ISSET(cli->socket, fd_read))
	cli->fct_read(info, cli->socket);
      if (FD_ISSET(cli->socket, fd_write))
	cli->fct_write(info, cli->socket);
      t = t->next;
    }
}

void		server_get(t_info *info)
{
  fd_set	fd_read;
  fd_set	fd_write;
  int		fd_max;

  debug("server_get()");
  FD_ZERO(&fd_read);
  FD_ZERO(&fd_write);
  get_set_fd(info->clients, &fd_read, &fd_write, &fd_max);
  if (select(fd_max + 1, &fd_read, &fd_write,
	     NULL, info->timeout) < 0)
    {
      printf("Error with select()\n");
      exit(-1);
    }
  get_isset_fd(info, &fd_read, &fd_write);
  printf("waiting...\n");
}
