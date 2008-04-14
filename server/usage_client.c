/*
** usage_client.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 12:06:08 2008 majdi toumi
** Last update Thu Apr 10 19:07:23 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include "zappy.h"

t_opt	gl_opt_clt[] = {
  {FLAG_X, "-n", "name_team"},
  {FLAG_X, "-p", "port"},
  {FLAG_X, "-h", "hostname"},
  {0, NULL, NULL, NULL}
};

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
