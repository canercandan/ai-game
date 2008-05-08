/*
** fork_in_the_word.c for Client Zappy 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 15 15:30:45 2008 florent hochwelker
** Last update Wed May  7 23:27:02 2008 caner candan
*/

#include <stdlib.h>
#include "client.h"
#include "x.h"

int	fork_in_the_word(t_info *info)
{
  if (xfork())
    return (-1);
  if (new_connection(info))
    exit(-1);
  enter_in_the_world(info);
  return (0);
}
