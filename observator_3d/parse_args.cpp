//
// parse_args.cpp for zappy in /home/candan_c/cu/rendu/project/zappy
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon May 12 14:27:30 2008 caner candan
// Last update Tue May 13 13:40:53 2008 jordan aubry
//

#include "observator_3d.h"
#include "common.h"

int	parse_args(int ac, char **av, t_obs *obs)
{
  if (ac > 2)
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
