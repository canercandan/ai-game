//
// extract_num.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:48:23 2008 majdi toumi
// Last update Mon May 12 19:21:20 2008 caner candan
//

#include "observator_3d.h"

int	extract_num(char *buf, int num)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < num)
    {
      while (buf[i] != '\n' && (buf[i] < '0' || buf[i] > '9'))
	i++;
      j++;
      if (j < num)
	{
	  while (buf[i] != '\n' && buf[i] >= '0' && buf[i] <= '9')
	    i++;
	}
    }
  num = 0;
  while (buf[i] != '\n' && buf[i] >= '0' && buf[i] <= '9')
    {
      num = num * 10 + (buf[i] - 48);
      i++;
    }
  return (num);
}
