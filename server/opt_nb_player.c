/*
** opt_nb_player.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:43:57 2008 majdi toumi
** Last update Fri Jun 13 19:24:53 2008 majdi toumi
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"

int	opt_nb_player(t_info *info, char **argv, int i)
{
  if (argv[i])
    {
      info->nb_player = atoi(argv[i]);
      i++;
    }
  else
    i = -1;
  return (i);
}
