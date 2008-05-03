/*
** server.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:10:57 2008 majdi toumi
** Last update Sat May  3 17:46:42 2008 florent hochwelker
*/

#include <stdlib.h>
#include <sys/time.h>
#include "server.h"

int		main(int ac, char **av)
{
  t_info	*info;

  debug("main()", 0);
  srandom(time(NULL));
  info = init_info();
  parse_args(ac, av, info);
  if (info == 0)
    usage_server();
  info->zone = create_world(info);
  add_server(info);
  server_get(info);
  free_info(info);
  return (0);
}
