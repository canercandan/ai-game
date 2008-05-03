/*
** send_info_to_obs.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May  3 15:19:05 2008 florent hochwelker
** Last update Sat May  3 16:10:51 2008 florent hochwelker
*/

#include <stdio.h>
#include "server.h"

/* static void	send_list_players() */
/* { */
/*   /\* ... *\/ */
/* } */

void	send_info_to_obs(t_client *client, t_info *info)
{
  snprintf(client->buf_write, BUF_SIZE, "%d_%d\n",
	   info->x, info->y);
}
