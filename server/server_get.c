/*
** server_get.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 10:20:01 2008 caner candan
** Last update Tue Apr 29 22:50:56 2008 caner candan
*/

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"
#include "server.h"

static void	get_set_fd(t_list *t, fd_set *fd_read, int *fd_max)
{
  fd_max = 0;
  while (t)
    {
      if (t->fd_type != FD_FREE)
	{
	  FD_SET(t->socket, &fd_read);
	  fd_max = t->socket;
	}
      t = t->next;
    }
}

static void	get_isset_fd(t_list *t, fd_set *fd_read)
{
  while (t)
    {
      if (FD_ISSET(t->socket, &fd_read))
	t->fct_read(e, i);
      t = t->next;
    }
}

void		server_get(t_env *e)
{
  fd_set	fd_read;
  int		fd_max;
  int		i;
  t_list	*t;

  FD_ZERO(&fd_read);
  get_set_fd(e->clients, &fd_read, &fd_max);
  if (select(fd_max + 1, &fd_read, NULL, NULL, e->timeout) < 0)
    {
      printf("Error with select()\n");
      exit(-1);
    }
  get_isset_fd(e->clients, &fd_read);
  printf("waiting...\n");
}
