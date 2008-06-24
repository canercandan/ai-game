/*
** parse_args.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:18:07 2008 majdi toumi
** Last update Tue Jun 24 14:44:59 2008 caner candan
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "common.h"
#include "x.h"

extern t_opt	gl_opt_srv[];

static char	*default_name_team[] =
  {"Team1", "Team2", 0};

static void	fill_default_info(t_info *info)
{
  info->port = DEFAULT_PORT;
  info->y = DEFAULT_LENGHT;
  info->x = DEFAULT_WIDTH;
  info->nb_player = DEFAULT_NB_PLAYER;
  opt_name_team(info, default_name_team, 0);
  info->time = 1.0 / DEFAULT_TIME;
  info->queue = 0;
  info->inithp = 10;
  info->coeff = 0.5;
}

void	parse_args(int argc, char **argv, t_info *info)
{
  int	flag;
  int	idx;
  int	i;

  fill_default_info(info);
  i = 1;
  flag = 0;
  while (i < argc)
    {
      if (((idx = is_options(argv[i])) != -1) && argv[++i])
	{
	  flag |= gl_opt_srv[idx].opt;
	  i = gl_opt_srv[idx].fun(info, argv, i);
	  if (i == -1)
	    usage_server();
	}
      else
	usage_server();
    }
/*   if (!check_flag(flag)) */
/*     usage_server(); */
}
