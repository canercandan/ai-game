/*
** is_levelup.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May  5 08:50:26 2008 caner candan
** Last update Mon May  5 13:45:22 2008 caner candan
*/

#include "server.h"

static t_level		level[] = {
  {1, 0, NULL},
  {2, 1, NULL},
  {3, 2, NULL},
  {4, 2, NULL},
  {5, 4, NULL},
  {6, 4, NULL},
  {7, 6, NULL},
  {8, 6, NULL}
};

static t_critere	critere[] = {
  {2, LINEMATE, 1},
  {3, LINEMATE, 1},
  {3, DERAUMERE, 1},
  {3, SIBUR, 1},
  {4, LINEMATE, 2},
  {4, SIBUR, 1},
  {4, PHIRAS, 2},
  {5, LINEMATE, 1},
  {5, DERAUMERE, 1},
  {5, SIBUR, 2},
  {5, PHIRAS, 1},
  {6, LINEMATE, 1},
  {6, DERAUMERE, 2},
  {6, SIBUR, 1},
  {6, MENDIANE, 3},
  {7, LINEMATE, 1},
  {7, DERAUMERE, 2},
  {7, SIBUR, 3}
};

int	is_levelup(t_info *info)
{
  return (0);
}
