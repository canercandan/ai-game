/*
** get_inventory_id.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 11:13:18 2008 caner candan
** Last update Mon Jun 23 01:32:45 2008 caner candan
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"
#include "common.h"

void			get_inventory_id(t_client *client, char *buff,
					 t_info *info)
{
  int			i;
  struct timeval	tp;

  i = 0;
  gettimeofday(&tp, NULL);
  while (i < NB_INVENTORY - 1)
    {
      putnbr(client->qte_ressource[i], buff);
      strcat(buff, " ");
      i++;
    }
  putnbr((client->hp - tp.tv_sec - tp.tv_usec / 1e6)
	 / (FOOD_HP * info->time), buff);
}
