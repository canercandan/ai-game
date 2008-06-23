/*
** obs_send_new_item.c for Zappy Server in /home/hochwe_f/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Wed Jun 11 13:43:30 2008 florent hochwelker
** Last update Mon Jun 23 01:37:17 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "common.h"

void	obs_send_new_item(t_list *obs, int x, int y, void *data)
{
  while (obs)
    {
      strcat(CLIENT(obs->data)->buf_write, NEW_ITEM);
      strcat(CLIENT(obs->data)->buf_write, " ");
      putnbr(x, CLIENT(obs->data)->buf_write);
      strcat(CLIENT(obs->data)->buf_write, " ");
      putnbr(y, CLIENT(obs->data)->buf_write);
      strcat(CLIENT(obs->data)->buf_write, " ");
      putnbr(((t_ressource*)data)->idx,
	     CLIENT(obs->data)->buf_write);
      strcat(CLIENT(obs->data)->buf_write, "\n");
      obs = obs->next;
    }
}
