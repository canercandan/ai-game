/*
** debug.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 14:44:07 2008 caner candan
** Last update Fri May  2 21:35:00 2008 caner candan
*/

#include <unistd.h>
#include <string.h>
#include "server.h"

void	debug(char *s, int pos)
{
  int	i;

  if (DEBUG)
    {
      write(1, "## DEBUG ##\t", 13);
      if (pos < 0)
	write(1, "## NOT POS ## ", 14);
      else
	for (i = 0; i < pos; i++)
	  {
	    if (i == pos - 1)
	      write(1, "+", 1);
	    write(1, "\t", 2);
	  }
      write(1, "-> ", 3);
      write(1, s, strlen(s));
      write(1, "\n", 2);
    }
}
