/*
** server.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:10:57 2008 majdi toumi
** Last update Thu Apr 10 18:36:25 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

int		main(int ac, char **av)
{
  t_info	*info;

  info = parse_args(ac, av);
  if (info == 0)
    usage_server();
  s = create_server(ac < 2 ? PORT_DEFAULT : av[1]);
  while ((cs = xaccept(s, NULL, NULL)) > 0)
    get_client(cs);
  close(s);
  return (1);
}
