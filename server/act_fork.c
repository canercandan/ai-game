/*
** act_fork.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May  5 08:27:53 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "common.h"

int	act_fork(char *param, t_client *client, t_info *info)
{
  (void)param;
  (void)info;
  send_buf_to_client(client, OK);
  return (0);
}
