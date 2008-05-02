/*
** trim.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  2 17:12:46 2008 florent hochwelker
** Last update Fri May  2 17:31:41 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"

char	*trim(char *str)
{
  int	i;

  i = 0;
  while (IS_PRINTABLE(str[i]))
    str++;
  i = strlen(str);
  while (IS_PRINTABLE(str[i]))
    {
      str[i] = 0;
      i--;
    }
  return (str);
}
