/*
** act_levelup.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Fri May  2 21:27:43 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"

int	act_levelup(char *cmd, t_client *client)
{
  (void)cmd;
  (void)client;
  strcpy(client->buf_write, "LEVELUP OK\n");
  return (0);
}
