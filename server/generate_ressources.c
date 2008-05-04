/*
** generate_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Wed Apr 30 13:55:01 2008 majdi toumi
** Last update Sun May  4 15:24:00 2008 caner candan
*/

#include "server.h"
#include "common.h"

t_ressource	gl_rock[] = {
  {LINEMATE, "Linemate", 0},
  {DERAUMERE, "Deraumere", 0},
  {SIBUR, "Sibur", 0},
  {MENDIANE, "Mendiane", 0},
  {PHIRAS, "Phiras", 0},
  {THYSTAME, "Thystame", 0},
  {0, 0, 0}
};

t_ressource	gl_food[] = {
  {HAMBURGER, "Hamburger", 0},
  {FISHBURGER, "Fishburger", 0},
  {CHEESEBURGER, "CHeeseburger", 0},
  {0, 0, 0}
};

t_ressource	*generate_ressources(int level_max, int i)
{
  t_ressource	*ressource;
  int		alea;

  if ((i % 2) == 0)
    {
      alea = get_random(level_max + 1);
      ressource = &gl_rock[alea];
    }
  else
    {
      alea = get_random(NB_FOOD);
      ressource = &gl_food[alea];
    }
  return (ressource);
}
