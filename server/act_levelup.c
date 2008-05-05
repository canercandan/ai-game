/*
** act_levelup.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May  5 16:53:49 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "common.h"

int	act_levelup(char *param, t_client *client, t_info *info)
{
  (void)param;
  if (!is_levelup(info, client))
    send_buf_to_client(client, KO);
  send_buf_to_client(client, LVLUP_PROCESS);
  return (0);
}
