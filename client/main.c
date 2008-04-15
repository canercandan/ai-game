/*
** main.c for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 18:25:32 2008 florent hochwelker
<<<<<<< .mine
** Last update Tue Apr 15 17:35:25 2008 florent hochwelker
=======
** Last update Tue Apr 15 17:30:46 2008 caner candan
>>>>>>> .r44
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"

int	main(int ac, char **av)
{
  int	socket;
  char	hostname;

  if (ac == 5)
    {
      hostname = "localhost";
      socket = new_connection(av[2], "localhost", atoi(av[4]));
    }
  else if (ac == 7)
    {
      hostname = av[6];
      socket = new_connection(av[2], av[6], atoi(av[4]));
    }
  else
    print_usage(av[0]);
  enter_in_the_world(socket, av[2], hostname, atoi(av[4]));
  return (0);
}
