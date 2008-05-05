/*
** act_inventory.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May  5 08:27:57 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "common.h"

int	act_inventory(char *param, t_client *client, t_info *info)
{
  (void)param;
  (void)info;
  /* ici fonction qui copie dans client->buf_write le debut de
     l'inventaire */
  /* Si on a pas fini de copier tout l'inventaire alors */
  /* create_new_queue puis push_list(&info->queue, new_queue) (voir execute_action) */
  /* et on set une variable dans client pour dire on c arrete au neme objet */
  send_buf_to_client(client, OK);
  return (0);
}
