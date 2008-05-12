/*
** debug.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 14:44:07 2008 caner candan
** Last update Mon May 12 13:50:01 2008 majdi toumi
*/

#include <unistd.h>
#include <string.h>
#include "common.h"

void	debug(char *s, int pos)
{
  int	i;

  if (DEBUG)
    {
      write(1, "## DEBUG ##\t", 13);
      if (pos < 0)
	write(1, "## NOT POS ## ", 14);
      else
	{
	  i = 0;
	  while (i < pos)
	    {
	      if (i == pos - 1)
		write(1, "+", 1);
	      write(1, "\t", 2);
	      i++;
	    }
	}
      write(1, "-> ", 3);
      write(1, s, strlen(s));
      write(1, "\n", 2);
    }
}
