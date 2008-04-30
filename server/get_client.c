/*
** get_client.c<2> for **zappy** in /u/epitech_2010s/candan_c/cu/rendu/c/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr 10 18:55:19 2008 caner candan
** Last update Thu Apr 10 19:12:36 2008 caner candan
*/

#include <stdlib.h>
#include <strings.h>
#include "server.h"

void	get_client(t_cnt *c)
{
  char	buf[1024];
  int	nbr;
  int	pid;

  if (!(pid = fork()))
    {
      bzero(buf, sizeof(buf));
      while ((nbr = xrecv(f->cs, buf, sizeof(buf), 0)) > 0)
	{
	}
      close(c->cs);
      exit(0);
    }
}
