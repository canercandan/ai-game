/*
** destroy_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 20:16:58 2008 caner candan
** Last update Wed May 14 11:47:46 2008 caner candan
*/

#include <unistd.h>
#include <stdlib.h>
#include "observator_2d.h"

void		destroy_info(t_info *info)
{
  t_list	*clients;
  t_client	*client;

  close(info->socket);
  clients = info->clients;
  while ((client = pop_list(&clients)))
    {
      free(client->team_name);
      free(client);
    }
}
