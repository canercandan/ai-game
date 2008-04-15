/*
** xsocket.c for x in /home/candan_c/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu Apr  3 09:24:30 2008 caner candan
** Last update Tue Apr 15 16:16:27 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "x.h"

int	xsocket(int domain, int type, int protocol)
{
  int	s;

  if ((s = socket(domain, type, protocol)) < 0)
    {
      fprintf(stderr, "Error with socket()\n");
      close(s);
      exit(FALSE);
    }
  return (s);
}