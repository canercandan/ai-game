/*
** server.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:10:57 2008 majdi toumi
** Last update Tue Apr 29 19:11:40 2008 caner candan
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include "zappy.h"
#include "server.h"

int		main(int ac, char **av)
{
  t_env		e;
  t_info	*info;
  t_zone	**zone;

  info = parse_args(ac, av);
  if (info == 0)
    usage_server();
  server_init(&e, av[1]);
  while (42)
    server_get(&e);
  zone = create_zone(info->width, info->lenght);
  return (0);
}
