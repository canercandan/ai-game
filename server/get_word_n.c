/*
** get_word_n.c for my_ftp_server in /u/epitech_2010s/hochwe_f/cu/rendu/c/my_ftp/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr  1 11:13:29 2008 florent hochwelker
** Last update Fri Apr  4 18:28:07 2008 florent hochwelker
*/

#include "my.h"

char	*get_word_n(char *str, int n)
{
  int	i;
  int	count;

  i = 0;
  count = n;
  while (--count)
    {
      while (str[i] != ' ')
	i++;
      i++;
    }
  return (str + i);
}
