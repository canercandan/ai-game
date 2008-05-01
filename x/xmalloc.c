/*
** xmalloc.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 16:32:19 2008 majdi toumi
** Last update Thu May  1 15:00:48 2008 caner candan
*/

#include <stdlib.h>
#include <stdio.h>
#include "x.h"

void	*xmalloc(int size)
{
  void	*p;

  p = malloc(size);
  if (p == NULL)
    {
      perror("xmalloc: not enough memory\n");
      exit(EXIT_FAIL);
    }
  return (p);
}
