/*
** init_random.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun May  4 11:38:40 2008 caner candan
** Last update Thu May 15 16:36:38 2008 caner candan
*/

#include <stdlib.h>
#include <sys/time.h>
#include "server.h"

void	init_random(void)
{
  srandom(time(NULL));
}
