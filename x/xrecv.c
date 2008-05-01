/*
** xrecv.c for x in /home/candan_c/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:48:28 2008 caner candan
** Last update Thu May  1 14:53:53 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

int	xrecv(int s, void *buf, int len, int flags)
{
  int	rc;

  if ((rc = recv(s, buf, (size_t) len, flags)) < 0)
    {
      perror("recv");
      close(s);
    }
  return (rc);
}
