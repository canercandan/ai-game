/*
** act_bird.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Mon May 12 21:19:27 2008 florent hochwelker
** Last update Tue Jun 24 14:45:34 2008 caner candan
*/

#include <sys/time.h>
#include "server.h"

int			act_bird(char *param, t_client *cli, t_info *info)
{
  t_client		*client;
  struct timeval	tp;

  gettimeofday(&tp, NULL);
  client = add_client(info, 0,
		      EXPLODEY(*((long *)(param))),
		      EXPLODEX(*((long *)(param))));
  info->zone[EXPLODEY(*((long *)(param)))]
    [EXPLODEX(*((long *)(param)))].nb_egg--;
  client->team = cli->team;
  client->socket = 0;
  client->status = ST_DISCONNECT;
  client->hp = tp.tv_sec + info->inithp * FOOD_HP * info->time;
  client->team->max++;
  obs_new_client(info->observator, client, info, 1);
  return (0);
}
