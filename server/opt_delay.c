/*
** opt_delay.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:44:27 2008 majdi toumi
** Last update Wed Apr 30 12:28:58 2008 majdi toumi
*/

#include <stdlib.h>
#include "server.h"

int	opt_delay(t_info *info, char **argv, int i)
{
  if (argv[i])
    info->time = atoi(argv[i]);
  return (i + 1);
}
