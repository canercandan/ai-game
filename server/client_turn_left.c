/*
** client_turn_right.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu May  1 18:17:38 2008 majdi toumi
** Last update Thu May  1 18:21:20 2008 majdi toumi
*/

#include "server.h"

char		*client_turn_left(t_client *client)
{
  int		direction;

  direction = client->direction;
  client->direction = (direction == NORTH ? WEST :
		       direction == WEST ? SOUTH :
		       direction == SOUTH ? EAST : NORTH);
  return ("ok");
}
