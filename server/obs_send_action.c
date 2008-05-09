/*
** obs_send_action.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  9 15:49:07 2008 florent hochwelker
** Last update Fri May  9 17:45:17 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"

void		obs_send_action(int socket, t_info *info, char idx_f, char *param)
{
  t_list	*obs;

  obs = info->observator;
  while (obs)
    {
      putnbr(socket, CLIENT(obs->data)->buf_write);
      strcat(CLIENT(obs->data)->buf_write, " ");
      putnbr(idx_f, CLIENT(obs->data)->buf_write);
      strcat(CLIENT(obs->data)->buf_write, " ");
      strcat(CLIENT(obs->data)->buf_write, param);
      strcat(CLIENT(obs->data)->buf_write, "\n");
      obs = obs->next;
    }
}
