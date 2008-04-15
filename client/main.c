/*
** main.c for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 18:25:32 2008 florent hochwelker
** Last update Thu Apr 10 19:32:48 2008 florent hochwelker
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int	main(int ac, char **av)
{
  int	socket;

  if (ac == 5)
    socket = new_connection(av[2], atoi(av[4]), "localhost");
  else if (ac == 7)
    socket = new_connection(av[2], atoi(av[4]), av[6]);
  else
    printf_usage(av[0]);
  enter_in_the_world(socket, av[2]);
  return (0);
}
