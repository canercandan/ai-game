/*
** act_broadcast.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Sat May  3 13:53:58 2008 caner candan
*/

#include <string.h>
#include "server.h"

int	act_broadcast(char *param, t_client *client, t_info *info)
{
  (void)cmd;
  (void)client;
  strcat(client->buf_write, "BROADCAST OK\n");
  return (0);
}
