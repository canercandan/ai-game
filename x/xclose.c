/*
** xclose.c for *zappy* in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 18:00:00 2008 caner candan
** Last update Thu May  1 14:54:16 2008 caner candan
*/

#include <unistd.h>
#include <stdio.h>
#include "x.h"

int	xclose(int fd)
{
  int	rc;

  if ((rc = close(fd)) < 0)
    perror("close");
  return (rc);
}
