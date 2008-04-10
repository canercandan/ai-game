/*
** server.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:10:57 2008 majdi toumi
** Last update Thu Apr 10 16:44:54 2008 majdi toumi
*/

#include <stdio.h>
#include "server.h"

int		main(int ac, char **av)
{
  t_info		info;

  info = parse_args(ac, av);
  if (!check_infos(&info))
    usage_server();
  else
    printf("ok\n");
  return (1);
}