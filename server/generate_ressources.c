/*
** generate_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Wed Apr 30 13:55:01 2008 majdi toumi
** Last update Sat May  3 14:14:02 2008 caner candan
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"

t_ressource	*generate_ressources(int level_max, int i)
{
  t_ressource	*ressource;
  int		alea;

  if ((i % 2) == 0)
    {
      alea = (int)(rand() / (double)RAND_MAX * (level_max + 1));
      ressource = &gl_rock[alea];
    }
  else
    {
      alea = (int)(rand() / (double)RAND_MAX * (NB_FOOD));
      ressource = &gl_food[alea];
    }
  return (ressource);
}
