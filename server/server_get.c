/*
** server_get.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 10:20:01 2008 caner candan
** Last update Fri May  2 14:59:38 2008 caner candan
*/

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "server.h"

static void	get_set_fd(t_list *t, fd_set *fd_read,
			   fd_set *fd_write, int *fd_max)
{
  t_client	*client;

  debug("get_set_fd()", 2);
  while (t)
    {
      client = t->data;
      FD_SET(client->socket, fd_read);
      if (client->buf_write[0] != 0)
	FD_SET(client->socket, fd_write);
      if (*fd_max < client->socket)
	*fd_max = client->socket;
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

static void	*get_timeout(t_info *info)
{
  if (((struct timeval *) info->timeout)->tv_sec == 0)
    return (NULL);
  return (info->timeout);
}

void		server_get(t_info *info)
{
  fd_set	fd_read;
  fd_set	fd_write;
  int		fd_max;

  debug("server_get()", 1);
  while (42)
    {
      FD_ZERO(&fd_read);
      FD_ZERO(&fd_write);
      fd_max = 0;
      get_set_fd(info->clients, &fd_read, &fd_write, &fd_max);
      if (select(fd_max + 1, &fd_read, &fd_write, NULL,
		 get_timeout(info)) < 0)
	{
	  printf("Error with select()\n");
	  exit(-1);
	}
      get_isset_fd(info, &fd_read, &fd_write);
      printf("waiting...\n");
    }
}
