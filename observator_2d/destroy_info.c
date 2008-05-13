/*
** destroy_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 20:16:58 2008 caner candan
** Last update Tue May 13 20:27:19 2008 caner candan
*/

#include <unistd.h>
#include <stdlib.h>
#include "observator_2d.h"

void		destroy_info(t_info *info)
{
  t_list	*clients;
  t_list	*inventories;
  t_client	*client;
  t_inventory	*inventory;

  close(info->socket);
  clients = info->clients;
  while ((client = pop_list(&clients)))
    {
      inventories = client->inventory;
      while ((inventory = pop_list(&inventories)))
	free(inventory);
      free(client->team_name);
      free(client);
    }
}
