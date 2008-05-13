/*
** act_fork.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May 12 21:30:14 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"
#include "common.h"

int	act_fork(char *param, t_client *client, t_info *info)
{
  (void)param;
  (void)info;
  SEND(client->buf_write, OK);
  return (0);
}
