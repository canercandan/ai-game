/*
** xfork.c for Zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 15 16:14:07 2008 florent hochwelker
** Last update Tue Apr 22 10:12:30 2008 florent hochwelker
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	xfork()
{
  int	pid;

  if ((pid = fork()) < 0)
    {
      perror("fork");
      exit(-1);
    }
  return (pid);
}
