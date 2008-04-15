/*
** xbind.c for x in /home/candan_c/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:27:50 2008 caner candan
** Last update Tue Apr 15 16:12:58 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

int	xbind(int s, const void *addr, void *addrlen)
{
  int	rc;

  if ((rc = bind(s, (struct sockaddr *) addr,
		 (socklen_t) addrlen)) < 0)
    {
      fprintf(stderr, "server - error with bind()\n");
      close(s);
      exit(FALSE);
    }
  return (rc);
}
