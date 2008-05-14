/*
** put_float_from_buf.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May 14 08:34:39 2008 caner candan
** Last update Wed May 14 08:34:50 2008 caner candan
*/

#include <string.h>
#include <stdlib.h>
#include "observator_2d.h"

void	put_float_from_buf(float *elm, char **buf)
{
  char	*str;

  if ((str = strsep(buf, DELIMIT)))
    *elm = atof(str);
}
