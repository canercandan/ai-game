/*
** parse_args.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:18:07 2008 majdi toumi
** Last update Thu Apr 10 11:52:24 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

t_opt	gl_opt[] = {
  {"-p", "port's number"},
  {"-x", "world's with"},
  {"-y", "world's length"},
  {"-n", "name_team_number1 name_team_number2 ..."},
  {"-c", "number of client at the begining"},
  {"-t", "temporal execution action's time measurement"},
  {NULL, NULL}
};

void	usage_server()
{
  int	i;

  i = 0;
  fprintf(stdout, "usage: \n");
  while (gl_opt[i].name != NULL)
    {
      fprintf(stdout, "%s %s\n", gl_opt[i].name, gl_opt[i].desc);
      i++;
    }
  exit(EXIT_SUCC);
}

int		parse_args(int argc, char **argv)
{
  t_info	info;
  int		i;

  i = 0;
  while (i < argc)
    {
      while (gl_opt[i].name != NULL)
	{
	  if (!strcmp(gl_opt[i].name, argv[i]))
	    {
	      fprintf(stdout, "ok");
	    }
	  j++;
	}
      i++;
    }
}
