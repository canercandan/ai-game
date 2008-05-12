//
// parse_args.cpp for zappy in /home/candan_c/cu/rendu/project/zappy
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon May 12 14:27:30 2008 caner candan
// Last update Mon May 12 15:04:10 2008 caner candan
//

#include "observator.h"
#include "common.h"

int	parse_args(int ac, char **av, t_obs *obs)
{
  if (ac == 3)
    {
      obs->host = av[1];
      obs->port = extract_num(av[2], 1);
      return (0);
    }
  else
    {
      obs->host = DEFAULT_HOST;
      obs->port = DEFAULT_PORT;
      return (0);
    }
  return (-1);
}
