/*
** act_left.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Fri May  2 21:26:51 2008 caner candan
*/

#include <string.h>
#include "server.h"

int	act_left(char *cmd, t_client *client)
{
  (void)cmd;
  (void)client;
  strcat(client->buf_write, "LEFT OK\n");
  return (0);
}
