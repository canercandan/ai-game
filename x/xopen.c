/*
** xopen.c for my_ftp_server in /u/epitech_2010s/hochwe_f/cu/rendu/c/my_ftp/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr  3 19:03:47 2008 florent hochwelker
** Last update Tue Apr 15 15:08:29 2008 florent hochwelker
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_ftp_server.h"

int	xopen(char *path, int flags)
{
  int	fd;

  if ((fd = open(path, flags)) > 0)
    return (fd);
  else
    {
      perror("xopen");
    }
}
