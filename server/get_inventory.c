/*
** get_inventory.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  9 00:43:10 2008 florent hochwelker
** Last update Mon Jun 23 01:32:05 2008 caner candan
*/

#include <string.h>
#include <sys/time.h>
#include "server.h"
#include "common.h"

void			get_inventory(t_client *client,
				      char *buff,
				      t_info *info)
{
  int			i;
  struct timeval	tp;

  i = 0;
  gettimeofday(&tp, NULL);
  strcpy(buff, START_CMD);
  strcat(buff, gl_ressource[NB_INVENTORY - 1].name);
  strcat(buff, SEPARATOR_ELM);
  putnbr((client->hp - tp.tv_sec - tp.tv_usec / 1e6) / (FOOD_HP * info->time),
	 buff);
  while (i < NB_INVENTORY - 1)
    {
      if (i != (NB_INVENTORY - 1))
	strcat(strcat(buff, SEPARATOR_CMD), SEPARATOR_ELM);
      strcat(buff, gl_ressource[i].name);
      strcat(buff, SEPARATOR_ELM);
      putnbr(client->qte_ressource[i], buff);
      i++;
    }
  strcat(buff, END_CMD);
}
