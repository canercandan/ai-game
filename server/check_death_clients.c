/*
** check_death_clients.c for zappy in /home/candan_c/rendu/c/zappy/server
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Jun 23 03:23:10 2008 caner candan
** Last update Mon Jun 23 03:46:52 2008 caner candan
*/

#include <sys/time.h>
#include <string.h>
#include "server.h"
#include "common.h"

static void	itsok(t_info *info, t_client *cli, t_list *clients)
{
  rm_client_from_queue(&info->queue, cli->socket, info);
  if (cli->status == ST_DISCONNECT)
    {
      rm_data_from_list(&info->clients, clients->data);
      free_client(clients->data);
      cli->team->nb++;
    }
  else
    {
      cli->status = ST_DEAD;
      strcpy(cli->buf_write, DEAD);
      obs_send_action(cli->id, info, DEATH, "");
    }
}

void		check_death_clients(t_info *info, void *tp)
{
  t_list	*clients;
  t_client	*cli;

  clients = info->clients;
  while (clients && (cli = clients->data))
    {
      if ((cli->status == ST_CLIENT || cli->status == ST_DISCONNECT) &&
	  ((((int)cli->hp) < TIMEVAL(tp)->tv_sec) ||
	   (((int)cli->hp) == TIMEVAL(tp)->tv_sec &&
	    (cli->hp - (int)CLIENT(clients->data)->hp)
	    * 1e6 < TIMEVAL(tp)->tv_usec)))
	itsok(info, cli, clients);
      clients = clients->next;
    }
}
