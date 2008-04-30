/*
** debug.c for zappy in /home/candan_c/cu/rendu/project/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 20:42:28 2008 caner candan
** Last update Wed Apr 30 14:46:38 2008 caner candan
*/

#include <unistd.h>
#include <string.h>
#include "server.h"

void	debug(char *s, void *pos)
{
  int	i;

  if (DEBUG)
    {
      for (i = 0; i < (int) pos; i++)
	write(1, "-", 1);
      write(1, ">", 1);
      write(1, s, strlen(s));
      write(1, "\n", 2);
    }
}
