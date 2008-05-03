/*
** act_inventory.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Sat May  3 15:55:10 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"

int	act_inventory(char *param, t_client *client, t_info *info)
{
  (void)param;
  (void)client;
  (void)info;
  /* ici fonction qui copie dans client->buf_write le debut de
     l'inventaire */
  /* Si on a pas fini de copier tout l'inventaire alors */
  /* create_new_queue puis push_list(&info->queue, new_queue) (voir execute_action) */
  /* et on set une variable dans client pour dire on c arrete au neme objet */
  strcat(client->buf_write, "Inventory OK\n");
  return (0);
}
