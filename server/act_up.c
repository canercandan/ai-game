/*
** act_up.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
<<<<<<< .mine
** Last update Thu May  1 16:48:37 2008 majdi toumi
=======
** Last update Sat May  3 00:18:31 2008 florent hochwelker
>>>>>>> .r224
*/

#include <string.h>
#include "server.h"

int	act_up(char *cmd, t_client *client)
{
  (void)cmd;
  (void)client;
  strcat(client->buf_write, "UP OK\n");
  return (0);
}
