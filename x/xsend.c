/*
** xsend.c for x in /home/candan_c/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:51:31 2008 caner candan
** Last update Mon Jun 23 03:56:47 2008 florent hochwelker
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

int	xsend(int s, const void *msg, int len, int flags)
{
  int	rc;

  if ((rc = send(s, msg, (size_t)len, flags)) < 0)
    {
      perror("send");
      close(s);
    }
  return (rc);
}
