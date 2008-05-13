/*
** server_get.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 10:20:01 2008 caner candan
** Last update Tue May 13 19:32:25 2008 florent hochwelker
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
      if (client->status != ST_DISCONNECT)
	FD_SET(client->socket, fd_read);
      if (client->buf_write[0] != 0
	  && client->status != ST_DISCONNECT)
	FD_SET(client->socket, fd_write);
      if (*fd_max < client->socket
	  && client->status != ST_DISCONNECT)
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
      if (FD_ISSET(client->socket, fd_write) && client->status != ST_DISCONNECT)
	client->fct_write(info, client);
      if (FD_ISSET(client->socket, fd_read) && client->status != ST_DISCONNECT)
	client->fct_read(info, &client);
    }
}

static void		*get_timeout(t_info *info)
{
  if (((struct timeval *)info->timeout)->tv_sec == -1 &&
      ((struct timeval *)info->timeout)->tv_usec == -1)
    {
      printf("timeout NULL\n");
      return (NULL);
    }
  printf("timeout->tv_sec = %ld, timeout->tv_usec = %ld\n",
	 (long)TIMEVAL(info->timeout)->tv_sec, (long)TIMEVAL(info->timeout)->tv_usec);
  return (info->timeout);
}

static void		check_death_clients(t_info *info, struct timeval *tp)
{
  t_list		*clients;
  t_client		*cli;

  clients = info->clients;
  while (clients && (cli = clients->data))
    {
      if ((cli->status == ST_CLIENT || cli->status == ST_DISCONNECT)
	  && ((((int)cli->hp) < tp->tv_sec) ||
	      (((int)cli->hp) == tp->tv_sec &&
	       (cli->hp - (int)CLIENT(clients->data)->hp) * 1e6 < tp->tv_usec)))
	{
	  rm_client_from_queue(&info->queue, cli->socket, info);
	  if (cli->status == ST_DISCONNECT)
	    {
	      rm_data_from_list(&info->clients, clients->data);
	      free_client(clients->data);
	      cli->team->nb++;
	    }
	  else
	    {
	      cli->status = ST_DEAD;
	      strcpy(cli->buf_write, DEAD);
	    }
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
	  perror("select:");
	  exit(-1);
	}
      gettimeofday(&tp, NULL);
      get_isset_fd(info, &fd_read, &fd_write);
      check_death_clients(info, &tp);
      scheduler_exec(info, &tp);
      printf("waiting...\n");
    }
}
