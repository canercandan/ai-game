/*
** parse_args.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:18:07 2008 majdi toumi
** Last update Thu Apr 10 18:48:19 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

extern t_opt	gl_opt_srv[];

t_info		*parse_args(int argc, char **argv)
{
  t_info	*info;
  int		flag;
  int		idx;
  int		i;

  i = 1;
  flag = 0;
  info = xmalloc(sizeof(*info));
  while (i < argc)
    {
      if (((idx = is_options(argv[i])) != -1) && argv[++i])
	{
	  flag |= gl_opt_srv[idx].opt;
	  i = gl_opt_srv[idx].fun(info, argv, i);
	}
      else
	return (0);
    }
  if (check_flag(flag))
    return (info);
  else
    return (0);
}
