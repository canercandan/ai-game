/*
** server_get.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 10:20:01 2008 caner candan
** Last update Wed Apr 30 18:48:34 2008 caner candan
*/

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include "server.h"

static void	get_set_fd(t_list *t, fd_set *fd_read,
			   fd_set *fd_write, int *fd_max)
{
  t_client	*client;

  debug("get_set_fd()", 2);
  *fd_max = 0;
  while (t)
    {
      client = t->data;
      if (client->fd_type != FD_FREE)
	{
	  FD_SET(client->socket, fd_read);
	  FD_SET(client->socket, fd_write);
	  *fd_max = client->socket;
	}
      t = t->next;
    }
}

static void	get_isset_fd(t_info *info, fd_set *fd_read,
			     fd_set *fd_write)
{
  t_list	*t;
  t_client	*client;

  debug("get_isset_fd()", 2);
  t = info->clients;
  show_clients_from_list(t);
  while (t)
    {
      client = t->data;
      if (FD_ISSET(client->socket, fd_read))
	client->fct_read(info, client->socket);
      if (FD_ISSET(client->socket, fd_write))
	client->fct_write(info, client->socket);
      t = t->next;
    }
}

void		server_get(t_info *info)
{
  fd_set	fd_read;
  fd_set	fd_write;
  int		fd_max;

  debug("server_get()", 1);
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
