/*
** round_nbr.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May 14 11:09:23 2008 caner candan
** Last update Wed May 14 11:11:52 2008 caner candan
*/

#include "observator_2d.h"

float	round_nbr(float nbr)
{
  if (nbr - ((int) nbr) < 0.5)
    return ((int) nbr);
  return ((int) nbr + 1);
}
