/*
** parse_args.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:18:07 2008 majdi toumi
** Last update Fri May  2 19:00:21 2008 caner candan
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "x.h"

extern t_opt	gl_opt_srv[];

static char	*default_name_team[] =
  {"Team1", "Team2", 0};

static void	fill_default_info(t_info *info)
{
  debug("fill_default_info()", 2);
  info->port = DEFAULT_PORT;
  info->y = DEFAULT_LENGHT;
  info->x = DEFAULT_WIDTH;
  info->nb_player = DEFAULT_NB_PLAYER;
  opt_name_team(info, default_name_team, 0);
  info->time = DEFAULT_TIME;
  info->queue = 0;
}

t_info	*parse_args(int argc, char **argv, t_info *info)
{
  int	flag;
  int	idx;
  int	i;

  debug("parse_args()", 1);
  fill_default_info(info);
  i = 1;
  flag = 0;
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
/*   if (!check_flag(flag)) */
/*     exit(-1); */
  return (info);
}
