/*
** xmalloc.c for my_ftp_server in /u/epitech_2010s/hochwe_f/cu/rendu/c/my_ftp/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr  3 10:58:24 2008 florent hochwelker
** Last update Fri Apr  4 18:21:08 2008 florent hochwelker
*/

#include <stdlib.h>
#include <stdio.h>

void	*xmalloc(int size)
{
  void	*p;

  if ((p = malloc(size)))
    return (p);
  else
    {
      perror("malloc");
      exit(-1);
    }
}
