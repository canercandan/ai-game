/*
** server_write.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 20:15:33 2008 caner candan
** Last update Sat May  3 15:21:10 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

void	server_write(t_info *info, t_client *client)
{
  (void) info;
  (void) client;
  debug("server_write()", -1);
  printf("Je suis dans server_write\n");
}
