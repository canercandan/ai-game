/*
** xaccept.c for zappy in /home/candan_c/rendu/project/x
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:37:35 2008 caner candan
** Last update Thu May  1 14:54:53 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "x.h"

int	xaccept(int s, void *addr, void *addrlen)
{
  int	sd;

  if ((sd = accept(s, (struct sockaddr *) addr,
		   (socklen_t *) addrlen)) < 0)
    {
      perror("accept");
      close(s);
    }
  return (sd);
}
