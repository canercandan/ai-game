/*
** parse_args.c for zappy in /home/candan_c/cu/rendu/project/zappy/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May  7 22:13:32 2008 caner candan
** Last update Mon May 12 14:44:23 2008 caner candan
*/

#include <stdlib.h>
#include "client.h"
#include "common.h"

int	parse_args(int ac, char **av, t_info *info)
{
  if (ac != 5 && ac != 7)
    {
      print_usage(av[0]);
      free_info(info);
      return (-1);
    }
  info->team_name = av[2];
  info->host = (ac == 7 ? av[6] : DEFAULT_HOST);
  info->port = atoi(av[4]);
  return (0);
}
