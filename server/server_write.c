/*
** server_write.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 20:15:33 2008 caner candan
** Last update Fri May  2 21:51:47 2008 florent hochwelker
*/

#include <stdio.h>
#include "server.h"

void	server_write(t_info *info, int socket)
{
  debug("server_write()", -1);
  printf("Je suis dans server_write\n");
  (void) info;
  (void) socket;
}
