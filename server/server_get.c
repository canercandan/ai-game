/*
** server_get.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 10:20:01 2008 caner candan
** Last update Tue Apr 22 18:59:47 2008 caner candan
*/

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "zappy.h"

void		server_get(t_env *e)
{
  fd_set	fd_read;
  int		fd_max;
  int		i;

  FD_ZERO(&fd_read);
  fd_max = 0;
  for (i = 0; i < MAX_FD; i++)
    if (e->fd_type[i] != FD_FREE)
      {
	FD_SET(i, &fd_read);
	fd_max = i;
      }
  if (select(fd_max + 1, &fd_read, NULL, NULL, e->timeout) < 0)
    {
      printf("Error with select()\n");
      exit(-1);
    }
  for (i = 0; i < MAX_FD; i++)
    if (FD_ISSET(i, &fd_read))
      e->fct_read[i](e, i);
  printf("waiting...\n");
}
