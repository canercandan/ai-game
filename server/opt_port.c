/*
** opt_port.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:42:27 2008 majdi toumi
** Last update Mon Jun 23 01:59:55 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

int	opt_port(t_info *info, char **argv, int i)
{
  if (argv[i])
    {
      info->port = atoi(argv[i]);
      i++;
    }
  else
    i = -1;
  return (i);
}
