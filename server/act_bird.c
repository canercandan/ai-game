/*
** act_bird.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Mon May 12 21:19:27 2008 florent hochwelker
** Last update Wed May 14 11:55:56 2008 florent hochwelker
*/

#include <stdio.h>		/* a vire printf */
#include <sys/time.h>
#include "server.h"

int			act_bird(char *param, t_client *team, t_info *info)
{
  t_client		*client;
  struct timeval	tp;

  gettimeofday(&tp, NULL);
  client = add_client(info, 0,
		      EXPLODEY(*((long *)(param))), EXPLODEX(*((long *)(param))));
  printf("oeuf place en (%ld, %ld)\n", EXPLODEY((long)(*param)), EXPLODEX((long)(*param)));
  client->team = (t_team *)team;
  client->socket = 0;
  client->status = ST_DISCONNECT;
  client->hp = tp.tv_sec + START_UNIT_LIFE * FOOD_HP * info->time;
  ((t_team *)team)->max++;
  obs_new_client(info->observator, client, info);
  return (0);
}
