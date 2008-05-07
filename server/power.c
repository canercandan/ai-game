/*
** power.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May  7 10:59:34 2008 caner candan
** Last update Wed May  7 10:59:53 2008 caner candan
*/

#include "server.h"

int	power(int nb, int pwr)
{
  int	res;
  int	i;

  if (!pwr)
    return (1);
  if (pwr < 0)
    return (0);
  res = nb;
  for (i = 1; i < pwr; i++)
    res *= nb;
  return (res);
}
