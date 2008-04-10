/*
** parse_args.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:18:07 2008 majdi toumi
** Last update Thu Apr 10 17:21:47 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

extern t_opt	gl_opt_srv[];

t_info		parse_args(int argc, char **argv)
{
  t_info	info;
  int		i;
  int		idx;

  info = init_infos();
  i = 1;
  while (i < argc)
    {
      if ((idx = is_options(argv[i])) != -1)
	i = gl_opt_srv[idx].fun(&info, argv, i + 1);
      else
	break;
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
