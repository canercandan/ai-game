/*
** xconnect.c for my_ftp_server in /u/epitech_2010s/hochwe_f/cu/rendu/c/my_ftp/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Wed Apr  2 18:16:42 2008 florent hochwelker
** Last update Tue Apr 15 15:08:13 2008 florent hochwelker
*/

#include <sys/types.h>
#include <sys/socket.h>

int	xconnect(int s, const struct sockaddr *name, socklen_t namelen)
{
  if (connect(s, name, namelen) < 0)
    {
      perror("connect");
    }
  return (0);
}
