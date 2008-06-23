/*
** opt_nb_player.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:43:57 2008 majdi toumi
** Last update Mon Jun 23 02:00:00 2008 caner candan
*/

#include <stdlib.h>
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
