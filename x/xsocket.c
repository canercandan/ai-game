/*
** xsocket.c for my_ftp_server in /u/epitech_2010s/hochwe_f/cu/rendu/c/my_ftp/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Wed Apr  2 18:08:03 2008 florent hochwelker
** Last update Tue Apr 15 15:08:34 2008 florent hochwelker
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int	xsocket(int domain, int type, int protocol)
{
  int	s;

  if ((s = socket(domain, type, protocol)) < 0)
    {
      perror("socket");
    }
  return (s);
}
