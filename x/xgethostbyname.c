/*
** xgethostbyname.c for x in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Wed Apr  2 18:11:56 2008 florent hochwelker
** Last update Thu May  1 14:57:21 2008 caner candan
*/

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include "x.h"

struct hostent		*xgethostbyname(char *name)
{
  struct hostent	*h;

  if (!(h = gethostbyname(name)))
    perror("gethostbyname");
  return (h);
}
