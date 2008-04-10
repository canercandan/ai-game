/*
** parse_args.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:18:07 2008 majdi toumi
** Last update Thu Apr 10 12:12:48 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

extern t_opt	gl_opt_srv[];

int		parse_args(int argc, char **argv)
{
  t_info	info;
  int		i;

  i = 0;
  while (i < argc)
    {
      j = 0;
      if (is_options(argv[i]))
	i = my_getopt(&info, i);
      else
	return (0);
    }
  return (info);
}

int		is_options()
{
  int		i;

  i = 0;
  while (gl_opt_srv[i].name != NULL)
    {
      if (!strcmp(gl_opt_srv[i].name, argv[i]))
	return (1);
      i++;
    }
  return (0);
}
