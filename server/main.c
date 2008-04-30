/*
** server.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:10:57 2008 majdi toumi
** Last update Wed Apr 30 14:46:20 2008 caner candan
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

  debug("main()", NULL);
  info = parse_args(ac, av);
  if (info == 0)
    usage_server();
  server_init(info);
  while (42)
    server_get(info);
  zone = create_world(info->width, info->lenght);
  free(info);
  return (0);
}
