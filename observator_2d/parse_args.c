/*
** parse_args.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:26:29 2008 caner candan
** Last update Mon May 12 21:31:13 2008 caner candan
*/

#include <stdlib.h>
#include "observator_2d.h"
#include "common.h"

int	parse_args(int ac, char **av, t_info *info)
{
  if (ac == 3)
    {
      info->host = av[1];
      info->port = atoi(av[2]);
      return (0);
    }
  info->host = DEFAULT_HOST;
  info->port = DEFAULT_PORT;
  return (0);
}
