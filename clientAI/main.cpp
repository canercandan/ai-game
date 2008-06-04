//
// main.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 11:20:25 2008 caner candan
// Last update Wed Jun  4 08:12:44 2008 caner candan
//

#include <iostream>
#include <cstdlib>
#include "Socket.h"
#include "AI.h"

static bool	parse_args(int ac, char **av, AI& ai)
{
  if (ac == 2)
    {
      ai.setHost("localhost", 12345);
      ai.setTeamName(av[1]);
      return (true);
    }
  else if (ac == 3)
    {
      ai.setHost("localhost", atoi(av[2]));
      ai.setTeamName(av[1]);
      return (true);
    }
  else if (ac == 4)
    {
      ai.setHost(av[2], atoi(av[3]));
      ai.setTeamName(av[1]);
      return (true);
    }
  std::cout << "Usage: ./AI [Team Name] [Host] [Port]" << std::endl;
  return (false);
}

int	main(int ac, char **av)
{
  AI	ai;

  if (!parse_args(ac, av, ai))
    return (-1);
  if (!ai.connectToServer())
    return (-1);
  if (!ai.getHeader())
    return (-1);
  ai.actionRandom();
  return (0);
}
