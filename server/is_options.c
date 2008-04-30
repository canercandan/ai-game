/*
** is_options.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:45:37 2008 majdi toumi
** Last update Wed Apr 30 12:34:31 2008 caner candan
*/

#include <string.h>
#include "server.h"

extern t_opt	gl_opt_srv[];

int	is_options(char *args)
{
  int		i;

  i = 0;
  while (gl_opt_srv[i].opt != 0)
    {
      if (!strcmp(gl_opt_srv[i].name, args))
	return (i);
      i++;
    }
  return (-1);
}
