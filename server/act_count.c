/*
** act_count.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 15:53:41 2008 caner candan
** Last update Mon May 12 16:13:01 2008 caner candan
*/

#include "server.h"

int	act_count(char *param, t_client *client, t_info *info)
{
  (void) param;
  putnbr(count_list_with_same_team(info->clients, client->team),
	 client->buf_write);
  send_buf_to_client(client, "\n");
  return (0);
}
