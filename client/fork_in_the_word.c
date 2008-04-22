/*
** fork_in_the_word.c for Client Zappy 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 15 15:30:45 2008 florent hochwelker
** Last update Tue Apr 22 14:10:28 2008 florent hochwelker
*/

#include "x.h"
#include "client.h"

int	fork_in_the_word(char *team_name, char *hostname, int port)
{
  int	socket;

  if (xfork() == 0)
    {
      socket = new_connection(team_name, hostname, port);
      enter_in_the_world(socket, team_name, hostname, port);
    }
  return (0);
}
