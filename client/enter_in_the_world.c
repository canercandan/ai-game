/*
** enter_in_the_world.c for Client Zappy 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 19:18:20 2008 florent hochwelker
** Last update Tue Apr 15 18:23:00 2008 caner candan
*/

#include <stdlib.h>
#include <ctype.h>
#include "x.h"
#include "client.h"

static t_map	*get_x_y_map(int socket, char *buff)
{
  t_map		*map;

  map = malloc(sizeof(*map));
  buff = strchr(buff, '\n');
  if ((isdigit(*(buff + 1)) && strstr(buff, "\n")))
    {
      map->x = atoi(buff);
      map->y = atoi(strchr(buff, ' '));
    }
  else
    {
      free(buff);
      if ((buff = check_response(socket)) && isdigit(*buff)) /* un peu unsafe */
	{
	  map->x = atoi(buff);
	  map->y = atoi(strchr(buff, ' '));
	}
      else
	{
	  printf("Error not a valid map\n");
	  exit(-1);
	}
    }
  free(buff);
  return (map);
}

static t_map	*step_two(int socket, char *team_name, char *hostname, int port)
{
  int		count;
  char		*p;

  if ((p = check_response(socket)))
    {
      if (isdigit(*p))
	{
	  if (atoi(p) > 1)
	    fork_in_the_word(team_name, hostname, port);
	  return(get_x_y_map(socket, p));
	}
    }
  return (-1);
}

static int	step_one(int socket, char *team_name)
{
  int		count;
  char		*p;

  if ((p = check_response(socket)))
    {
      if (strncmp(p, MSG_WELCOME, strlen(MSG_WELCOME)) == 0)
	{
	  xsend(socket, team_name, strlen(team_name), 0);
	  xsend(socket, "\n", 1, 0);
	  free(p);
	  return (0);
	}
    }
  return (-1);
}

int	enter_in_the_world(int socket, char *team_name, char *hostname, int port)
{
  t_map	*map;

  if (step_one(socket, team_name) != -1 &&
      (map = step_two(socket, team_name, hostname, port)) != (t_map *)-1)
    {
      printf("[%d] I enter in the world\n", socket);
      printf("map X = %d, Y = %d", map->x, map->y);
    }
  close(socket);
}
