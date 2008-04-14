/*
** opt_lenght.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:43:14 2008 majdi toumi
** Last update Thu Apr 10 19:06:14 2008 majdi toumi
*/

#include <stdlib.h>
#include "zappy.h"

int	opt_lenght(t_info *info, char **argv, int i)
{
  if (argv[i])
    info->lenght = atoi(argv[i]);
  return (i + 1);
}
