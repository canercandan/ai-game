/*
** xconnect.c for x in /home/candan_c/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:53:56 2008 caner candan
** Last update Thu May  1 14:56:40 2008 caner candan
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
      perror("close");
      close(s);
    }
  return (s);
}
