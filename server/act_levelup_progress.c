/*
** act_levelup_progress.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Mon May 12 18:05:23 2008 florent hochwelker
** Last update Mon May 12 18:53:28 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"
#include "common.h"

int	act_levelup_progress(char *param, t_client *client, t_info *info)
{
  (void)param;
  (void)info;
  SEND(client->buf_write, LVLUP_PROCESS);
  return (0);
}
