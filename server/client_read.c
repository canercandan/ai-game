/*
** client_read.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:25:30 2008 caner candan
** Last update Tue Apr 22 18:08:32 2008 caner candan
*/

#include "server.h"
#include "x.h"
#include "zappy.h"

void	client_read(t_env *e, int fd)
{
  int	r;
  char	buf[4096];

  if ((r = (int) xrecv(fd, buf, sizeof(buf), NULL)) > 0)
    {
      buf[r] = '\0';
      printf("%d: %s\n", fd, buf);
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      xclose(fd);
      e->fd_type[fd] = FD_FREE;
    }
}
