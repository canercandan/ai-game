/*
** xgethostbyname.c for my_ftp_server in /u/epitech_2010s/hochwe_f/cu/rendu/c/my_ftp/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Wed Apr  2 18:11:56 2008 florent hochwelker
** Last update Tue Apr 15 15:08:21 2008 florent hochwelker
*/

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

struct hostent		*xgethostbyname(char *name)
{
  struct hostent	*h;

  if (!(h = gethostbyname(name)))
    {
      perror("gethostbyname");
    }
  return (h);
}
