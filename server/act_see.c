/*
** act_see.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Sat May  3 15:55:47 2008 caner candan
*/

#include <string.h>
#include "server.h"

int	act_see(char *param, t_client *client, t_info *info)
{
  int	x;
  int	y;
  int	i;
  int	j;

  (void)param;
  (void)info;
  x = client->x;
  y = client->y;

  strcat(client->buf_write, START_CMD);
  
  for (i = 0; i < client->level; i++)
    {
      strcat(client->buf_write, );
    }
  strcat(client->buf_write, END_CMD);
  return (0);
}
