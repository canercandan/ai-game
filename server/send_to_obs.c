/*
** send_to_obs.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  9 02:06:24 2008 florent hochwelker
** Last update Mon Jun 23 02:36:02 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"

void	send_to_obs(t_list *obs, char *str)
{
  while (obs)
    {
      strcat(CLIENT(obs->data)->buf_write, str);
      obs = obs->next;
    }
}
