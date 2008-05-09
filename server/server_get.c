/*
** server_get.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 10:20:01 2008 caner candan
** Last update Fri May  9 01:18:46 2008 florent hochwelker
*/

#include <sys/select.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include "common.h"
#include "server.h"

static void	get_set_fd(t_list *t, fd_set *fd_read,
			   fd_set *fd_write, int *fd_max)
{
  t_client	*client;

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

  t = info->clients;
  while (t)
    {
      client = t->data;
      t = t->next;
      if (FD_ISSET(client->socket, fd_write))
	client->fct_write(info, client);
      if (FD_ISSET(client->socket, fd_read))
	client->fct_read(info, client);
    }
}

static void		*get_timeout(t_info *info)
{
  if (((struct timeval *)info->timeout)->tv_sec == -1 &&
      ((struct timeval *)info->timeout)->tv_usec == -1)
    return (NULL);
  return (info->timeout);
}

static void		check_death_clients(t_info *info, unsigned int timestamp)
{
  t_list		*clients;

  clients = info->clients;
  while (clients)
    {
      if (((t_client *)clients->data)->status == ST_CLIENT
	  && ((t_client *)clients->data)->hp <= timestamp)
	{
	  rm_client_from_queue(&info->queue,
			       ((t_client *)clients->data)->socket, info);
	  ((t_client *)clients->data)->status = ST_DEAD;
	  strcpy(((t_client *)clients->data)->buf_write, DEAD);
	}
      clients = clients->next;
    }
}

void			server_get(t_info *info)
{
  fd_set		fd_read;
  fd_set		fd_write;
  int			fd_max;
  struct timeval	tp;

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
      gettimeofday(&tp, NULL);
      check_death_clients(info, tp.tv_sec);
      get_isset_fd(info, &fd_read, &fd_write);
      scheduler_exec(info, &tp);
      printf("tp.tv_sec = %ld, tp.tv_usec = %ld\n", tp.tv_sec, tp.tv_usec);
      printf("waiting...\n");
    }
}
