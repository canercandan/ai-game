/*
** client_turn_right.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu May  1 18:17:38 2008 majdi toumi
** Last update Thu May  1 18:20:45 2008 majdi toumi
*/

#include "server.h"

char		*client_turn_right(t_client *client)
{
  int		direction;

  direction = client->direction;
  client->direction = (direction == NORTH ? EAST :
		       direction == EAST ? SOUTH :
		       direction == SOUTH ? WEST : NORTH);
  return ("ok");
}
