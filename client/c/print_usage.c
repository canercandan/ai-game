/*
** print_usage.c for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 18:56:00 2008 florent hochwelker
** Last update Tue Apr 22 09:59:49 2008 florent hochwelker
*/

#include <stdio.h>
#include <stdlib.h>

void	print_usage(char *arg_zero)
{
  printf("Usage:\n%s -n team_name -p port [-h host]\n", arg_zero);
  exit(-1);
}
