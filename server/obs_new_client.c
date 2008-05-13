/*
** obs_new_client.c for  in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  9 02:32:45 2008 florent hochwelker
** Last update Tue May 13 22:59:43 2008 majdi
*/

#include "server.h"

void	obs_new_client(t_list *obs, t_client *client, t_info *info)
{
  while (obs)
    {
      obs_add_client_in_char(CLIENT(obs->data)->buf_write, client, info,
			     CLIENT(obs->data)->id);
      obs = obs->next;
    }
}
