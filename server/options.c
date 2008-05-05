/*
** options.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Mon May  5 15:32:49 2008 majdi toumi
** Last update Mon May  5 15:36:07 2008 majdi toumi
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "x.h"

static t_opt	gl_opt_srv[] = {
  {FLAG_P, "-p", "port's number", opt_port},
  {FLAG_X, "-x", "world's with", opt_width},
  {FLAG_Y, "-y", "world's length", opt_lenght},
  {FLAG_N, "-n", "name_team_number1 name_team_number2 ...", opt_name_team},
  {FLAG_C, "-c", "number of client at the begining", opt_nb_player},
  {FLAG_T, "-t", "temporal execution action's delay", opt_delay},
  {0, NULL, NULL, NULL}
};

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

int	is_options(char *args)
{
  int	i;

  i = 0;
  while (gl_opt_srv[i].opt != 0)
    {
      if (!strcmp(gl_opt_srv[i].name, args))
	return (i);
      i++;
    }
  return (-1);
}

void		usage_server()
{
  int	i;

  debug("usage_server()", 1);
  i = 0;
  fprintf(stdout, "\033[34musage: ./server\n");
  while (gl_opt_srv[i].opt != 0)
    {
      fprintf(stdout, "\t%s %s\n", gl_opt_srv[i].name, gl_opt_srv[i].desc);
      i++;
    }
  fprintf(stdout, "\033[0m");
  exit(EXIT_SUCC);
}

t_info		*parse_args(int argc, char **argv, t_info *info)
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
