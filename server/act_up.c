/*
** act_up.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Wed May  7 11:15:53 2008 caner candan
*/

#include "server.h"
#include "common.h"

int	act_up(char *param, t_client *client, t_info *info)
{
  (void) param;
  move_up(client, info);
  send_buf_to_client(client, OK);
  return (0);
}
