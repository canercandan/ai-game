/*
** server.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:10:57 2008 majdi toumi
** Last update Thu Apr 10 19:55:13 2008 majdi toumi
*/

#include <stdio.h>
#include "zappy.h"

int		main(int ac, char **av)
{
  t_info	*info;
  t_zone	**zone;

  info = parse_args(ac, av);
  if (info == 0)
    usage_server();
  zone = create_zone(info->width, info->lenght);
  //  s = create_server(ac < 2 ? PORT_DEFAULT : av[1]);
  //while ((cs = xaccept(s, NULL, NULL)) > 0)
  // get_client(cs);
  //close(s);
  //return (1);
  return (0);
}
