/*
** act_broadcast.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Fri May  2 21:25:29 2008 florent hochwelker
*/

#include "server.h"

int	act_broadcast(char *cmd, t_client *client)
{
  (void)cmd;
  (void)client;
  strcpy(client->buf_write, "BROADCAST OK\n");
  return (0);
}
