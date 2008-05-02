/*
** server.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:10:57 2008 majdi toumi
** Last update Fri May  2 15:30:40 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include "server.h"

int		main(int ac, char **av)
{
  t_info	*info;
  t_zone	**zone;

  debug("main()", 0);
  info = init_info();
  info = parse_args(ac, av, info);
  info->zone = init_zone(info);
  if (info == 0)
    usage_server();
  server_init(info);
  server_get(info);
  zone = create_world(info);
  free_info(info);
  return (0);
}
