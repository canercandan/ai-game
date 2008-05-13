/*
** client_read.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:25:30 2008 caner candan
** Last update Tue May 13 21:53:02 2008 florent hochwelker
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "x.h"

void		client_read(t_info *info, t_client **client)
{
  int		r;
  char		buf[BUF_SIZE + 1];
  char		buff_perso[BUF_SIZE + 1];
  char		*p;
  t_client	*check_respaw;

  if ((r = (int)xrecv((*client)->socket, buf, BUF_SIZE, 0)) > 0)
    {
      buf[r] = '\0';
      strncat((*client)->buf_read, buf, BUF_SIZE - strlen(buf));
      while ((p = strstr((*client)->buf_read, "\n")))
	{
	  *p = 0;
	  strncpy(buff_perso, (*client)->buf_read, BUF_SIZE - 1);
	  check_respaw = *client;
	  if ((*client)->status < ST_CLIENT)
	    begin_session(info, client);
	  else
	    execute_action(buff_perso, *client, info);
	  if (check_respaw == *client)
	    memmove((*client)->buf_read, p + 1, BUF_SIZE);
	}
    }
  else
    client_disconnect((*client), info);
}
