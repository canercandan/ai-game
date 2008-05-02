/*
** opt_width.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:52:30 2008 majdi toumi
** Last update Fri May  2 16:41:28 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

int		opt_width(t_info *info, char **argv, int i)
{
  if (argv[i])
    info->x = atoi(argv[i]);
  return (i + 1);
}
