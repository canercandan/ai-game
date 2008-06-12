/*
** act_fork.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Thu Jun 12 14:23:15 2008 florent hochwelker
*/

#include <stdio.h>		/* a vire printf */
#include <string.h>
#include "server.h"
#include "common.h"

int	act_fork(char *param, t_client *client, t_info *info)
{
  (void)param;
  (void)info;
  printf("le nombre est a %d", info->zone[client->x][client->y].nb_egg);
  info->zone[client->x][client->y].nb_egg++;
  printf(" il passe a %d\n", info->zone[client->x][client->y].nb_egg);
  SEND(client->buf_write, OK);
  return (0);
}
