/*
** opt_life for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:42:27 2008 majdi toumi
** Last update Tue Jun 24 14:45:21 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

int	opt_life(t_info *info, char **argv, int i)
{
  if (argv[i])
    {
      info->inithp = atof(argv[i]);
      i++;
    }
  else
    i = -1;
  return (i);
}
