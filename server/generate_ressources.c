/*
** generate_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Wed Apr 30 13:55:01 2008 majdi toumi
** Last update Tue May  6 15:52:00 2008 majdi toumi
*/

#include "server.h"
#include "common.h"

t_ressource	gl_ressource[] = {
  {LINEMATE, "linemate", 0},
  {DERAUMERE, "deraumere", 0},
  {SIBUR, "sibur", 0},
  {MENDIANE, "mendiane", 0},
  {PHIRAS, "phiras", 0},
  {THYSTAME, "thystame", 0},
  {NOURRITURE, "nourriture", 0},
  {-1, 0, 0}
};

t_ressource	*generate_ressources(int i)
{
  t_ressource	*ressource;
  int		alea;

  if ((i % 3) != 0)
    {
      alea = get_random(NB_INVENTORY - 1 + 1);
      ressource = &gl_ressource[alea];
    }
  else
    ressource = &gl_ressource[NB_INVENTORY - 1];
  return (ressource);
}
