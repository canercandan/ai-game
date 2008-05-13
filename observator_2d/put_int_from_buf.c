/*
** put_int_from_buf.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 16:33:00 2008 caner candan
** Last update Tue May 13 18:19:12 2008 caner candan
*/

#include <string.h>
#include <stdlib.h>
#include "observator_2d.h"

void	put_int_from_buf(int *elm, char **buf)
{
  char	*str;

  if ((str = strsep(buf, DELIMIT)))
    *elm = atoi(str);
}
