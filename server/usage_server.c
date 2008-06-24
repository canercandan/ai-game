/*
** usage_server.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 12:06:08 2008 majdi toumi
** Last update Tue Jun 24 12:19:45 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "common.h"

t_opt	gl_opt_srv[] = {
  {FLAG_P, "-p", "port's number", opt_port},
  {FLAG_X, "-x", "world's with", opt_width},
  {FLAG_Y, "-y", "world's length", opt_lenght},
  {FLAG_N, "-n", "name_team_number1 name_team_number2 ...", opt_name_team},
  {FLAG_C, "-c", "number of client at the begining", opt_nb_player},
  {FLAG_T, "-t", "temporal execution action's delay", opt_delay},
  {FLAG_K, "-k", "ressources's coefficient", opt_coeff},
  {FLAG_H, "--help", "help", opt_help},
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
