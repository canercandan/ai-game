/*
** get_inventory_id.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 11:13:18 2008 caner candan
** Last update Sat Jun  7 16:27:48 2008 florent hochwelker
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
  putnbr(gl_ressource[NB_INVENTORY - 1].idx, buff);
  strcat(buff, SEPARATOR_ELM);
  putnbr((client->hp - tp.tv_sec - tp.tv_usec / 1e6) / (FOOD_HP * info->time),
	 buff);
  while (i < NB_INVENTORY - 1)
    {
      strcat(buff, " ");
      /*      
	      if (i != (NB_INVENTORY - 1))
	      strcat(strcat(buff, SEPARATOR_CMD), SEPARATOR_ELM);
	      putnbr(gl_ressource[i].idx, buff);
      */
      putnbr(client->qte_ressource[i], buff);
      i++;
    }
}
