/*
** debug.c for zappy in /home/candan_c/cu/rendu/project/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 29 20:42:28 2008 caner candan
** Last update Wed Apr 30 12:27:10 2008 caner candan
*/

#include <unistd.h>
#include <string.h>
#include "server.h"

void	debug(char *s)
{
  if (DEBUG)
    write(1, s, strlen(s));
}
