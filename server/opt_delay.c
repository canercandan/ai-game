/*
** opt_delay.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:44:27 2008 majdi toumi
** Last update Thu Apr 10 19:06:07 2008 majdi toumi
*/

#include <stdlib.h>
#include "zappy.h"

int	opt_delay(t_info *info, char **argv, int i)
{
  if (argv[i])
    info->time = atoi(argv[i]);
  return (i + 1);
}
