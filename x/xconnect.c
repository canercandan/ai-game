/*
** xconnect.c for x in /home/candan_c/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:53:56 2008 caner candan
** Last update Wed May  7 23:36:34 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

int	xconnect(int s, const void *name, void *namelen)
{
  int	rc;

  if ((rc = connect(s, (struct sockaddr *) name,
		    (socklen_t) namelen)) < 0)
    {
      perror("connect");
      close(s);
    }
  return (rc);
}
