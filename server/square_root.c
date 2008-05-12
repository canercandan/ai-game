/*
** square_root.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May  7 10:59:18 2008 caner candan
** Last update Mon May 12 13:11:21 2008 majdi toumi
*/

#include "server.h"

int	square_root(int nb)
{
  int	i;

  i = 0;
  while (i * i <= nb)
    i++;
  if (i * i == nb)
    return (i);
  return (i - 1);
}
