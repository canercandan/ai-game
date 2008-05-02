/*
** check_response.c for FTP server in /u/epitech_2010s/hochwe_f/cu/rendu/c/my_ftp/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri Apr 11 17:25:55 2008 florent hochwelker
** Last update Fri May  2 17:50:17 2008 florent hochwelker
*/

#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "x.h"

char	*check_response(int socket)
{
  char	buff[1024 + 1];
  char	*ret_buff;
  int	count;

  ret_buff = xmalloc(sizeof(*ret_buff) * (1024 + 1));
  buff[1024] = 0;
  bzero(ret_buff, 1025);
  bzero(buff, 1024);
  while ((count = recv(socket, buff, 1024, 0)))
    {
      buff[count] = 0;
      strlcat(ret_buff, buff, 1024);
      if (strstr(ret_buff, "\n"))
	return (ret_buff);
      bzero(buff, 1024);
    }
  return (0);
}
