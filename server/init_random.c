/*
** init_random.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sun May  4 11:38:40 2008 caner candan
** Last update Sun May  4 11:39:17 2008 caner candan
*/

#include <stdlib.h>
#include <sys/time.h>

void	init_random(void)
{
  srandom(time(NULL));
}
