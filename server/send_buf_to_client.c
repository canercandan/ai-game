/*
** send_buf_to_client.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May  5 08:10:47 2008 caner candan
** Last update Mon May  5 08:19:53 2008 caner candan
*/

#include <string.h>
#include "server.h"

int	send_buf_to_client(t_client *client, char *buf)
{
  if ((strlen(client->buf_write) + strlen(buf)) > BUF_SIZE)
    return (-1);
  strcat(client->buf_write, buf);
  return (0);
}
