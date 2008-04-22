/*
** xopen.c for x in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr  3 19:03:47 2008 florent hochwelker
** Last update Tue Apr 22 18:03:57 2008 caner candan
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "x.h"

int	xopen(char *path, int flags)
{
  int	fd;

  if ((fd = open(path, flags)) < 0)
    printf("Error with open()\n");
  return (fd);
}
