/*
** act_fork.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May 12 16:27:58 2008 majdi toumi
*/

#include <string.h>
#include "server.h"
#include "common.h"

int	act_fork(char *param, t_client *client, t_info *info)
{
  (void)param;
  (void)info;
  client->team->max++;
  SEND(client->buf_write, OK);
  return (0);
}
