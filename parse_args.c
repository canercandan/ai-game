/*
** parse_args.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:18:07 2008 majdi toumi
** Last update Thu Apr 10 14:41:51 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

extern t_opt	gl_opt_srv[];

t_info		parse_args(int argc, char **argv)
{
  t_info	info;
  int		i;

  i = 0;
  while (i < argc)
    {
      if (is_options(argv[i]) != -1)
	i = gl_opt_srv[i].fun(&info, argv, i + 1);
      else
	return (0);
    }
  return (info);
}



int		is_options(char *args)
{
  int		i;

  i = 0;
  while (gl_opt_srv[i].name != NULL)
    {
      if (!strcmp(gl_opt_srv[i].name, args))
	return (i);
      i++;
    }
  return (-1);
}
