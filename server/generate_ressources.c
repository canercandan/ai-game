/*
** generate_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Wed Apr 30 13:55:01 2008 majdi toumi
** Last update Mon May  5 16:44:31 2008 majdi toumi
*/

#include "server.h"
#include "common.h"

t_ressource	gl_ressource[] = {
  {LINEMATE, "Linemate", 0},
  {DERAUMERE, "Deraumere", 0},
  {SIBUR, "Sibur", 0},
  {MENDIANE, "Mendiane", 0},
  {PHIRAS, "Phiras", 0},
  {THYSTAME, "Thystame", 0},
  {HAMBURGER, "Hamburger", 0},
  {0, 0, 0}
};

t_ressource	*generate_ressources(int level_max, int i)
{
  t_ressource	*ressource;
  int		alea;

  if ((i % 3) != 0)
    {
      alea = get_random(level_max + 1);
      ressource = &gl_ressource[alea];
    }
  else
    ressource = &gl_ressource[NB_INVENTORY - 1];
  return (ressource);
}
