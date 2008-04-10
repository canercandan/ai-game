/*
** usage.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 12:06:08 2008 majdi toumi
** Last update Thu Apr 10 17:39:22 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

t_opt	gl_opt_srv[] = {
  {FLAG_P, "-p", "port's number", get_port},
  {FLAG_X, "-x", "world's with", get_width},
  {FLAG_Y, "-y", "world's length", get_lenght},
  {FLAG_N, "-n", "name_team_number1 name_team_number2 ...", get_name_team},
  {FLAG_C, "-c", "number of client at the begining", get_nb_player},
  {FLAG_T, "-t", "temporal execution action's delay", get_delay},
  {0, NULL, NULL, NULL}
};

t_opt	gl_opt_clt[] = {
  {FLAG_X, "-n", "name_team"},
  {FLAG_X, "-p", "port"},
  {FLAG_X, "-h", "hostname"},
  {0, NULL, NULL, NULL}
};

void	usage_server()
{
  int	i;

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

void	usage_client()
{
  int	i;

  i = 0;
  fprintf(stdout, "\033[34musage: ./client\n");
  while (gl_opt_clt[i].opt != 0)
    {
      fprintf(stdout, "\t%s %s\n", gl_opt_clt[i].name, gl_opt_clt[i].desc);
      i++;
    }
  fprintf(stdout, "\033[0m");
  exit(EXIT_SUCC);
}
