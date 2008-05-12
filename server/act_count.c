/*
** act_count.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 15:53:41 2008 caner candan
** Last update Mon May 12 17:47:37 2008 caner candan
*/

#include <string.h>
#include "server.h"

int	act_count(char *param, t_client *client, t_info *info)
{
  (void) param;
  (void) info;
  putnbr(client->team->nb, client->buf_write);
  SEND(client->buf_write, "\n");
  return (0);
}
