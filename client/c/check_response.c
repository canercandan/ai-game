/*
** check_response.c for FTP server in /u/epitech_2010s/hochwe_f/cu/rendu/c/my_ftp/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri Apr 11 17:25:55 2008 florent hochwelker
** Last update Wed May  7 23:23:50 2008 caner candan
*/

#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "client.h"
#include "x.h"

char	*check_response(t_info *info)
{
  char	buff[BUF_SIZE + 1];
  char	*ret_buff;
  int	count;

  ret_buff = xmalloc(sizeof(*ret_buff) * (BUF_SIZE + 1));
  buff[BUF_SIZE] = 0;
  bzero(ret_buff, BUF_SIZE + 1);
  bzero(buff, BUF_SIZE);
  while ((count = recv(info->socket, buff, BUF_SIZE, 0)) > 0)
    {
      buff[count] = 0;
      strlcat(ret_buff, buff, count + 1);
      if (strstr(ret_buff, "\n"))
	return (ret_buff);
      bzero(buff, BUF_SIZE);
    }
  return (0);
}
