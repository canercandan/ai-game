/*
** main.c for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 18:25:32 2008 florent hochwelker
** Last update Wed May  7 23:34:42 2008 caner candan
*/

#include "client.h"

int		main(int ac, char **av)
{
  t_info	*info;

  info = init_info();
  if (parse_args(ac, av, info) < 0)
    return (-1);
  if (new_connection(info) < 0)
    return (-1);
  enter_in_the_world(info);
  free_info(info);
  return (0);
}
