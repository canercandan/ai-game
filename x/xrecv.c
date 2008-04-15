/*
** xrecv.c for x in /home/candan_c/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:48:28 2008 caner candan
** Last update Tue Apr 15 16:15:35 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

void	*xrecv(int s, void *buf, void *len, int flags)
{
  void	*rc;

  if ((int) (rc = (void *) recv(s, buf, (size_t) len, flags)) < 0)
    {
      fprintf(stderr, "Error with recv()\n");
      close(s);
      exit(FALSE);
    }
  return (rc);
}
