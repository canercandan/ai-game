/*
** put_char_from_buf.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 16:32:07 2008 caner candan
** Last update Tue May 13 18:19:22 2008 caner candan
*/

#include <string.h>
#include "observator_2d.h"

void	put_char_from_buf(char **elm, char **buf)
{
  char	*str;

  if ((str = strsep(buf, DELIMIT)))
    *elm = strdup(str);
}
