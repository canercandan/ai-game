/*
** my_putnbr.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Wed May  7 11:37:06 2008 majdi toumi
** Last update Fri May  9 01:47:44 2008 florent hochwelker
*/

#include <string.h>

void	putnbr(unsigned int n, char *buff)
{
  int	rest;
  char	c;

  rest = n % 10;
  n = n / 10;
  if (n != 0)
    putnbr(n, buff);
  c = rest + '0';
  strncat(buff, &c, 1);
}
