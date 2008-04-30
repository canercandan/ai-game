/*
** list_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:05:04 2008 majdi toumi
** Last update Wed Apr 30 13:02:24 2008 majdi toumi
*/

#include <stdlib.h>
#include "server.h"

enum
  {
    LINEMATE = 1,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  };

enum
  {
    HAMBURGER = 1,
    FISHBURGER,
    CHEESEBURGER
  };

t_ressource	gl_rock[] = {
  {LINEMATE, "Linemate"},
  {DERAUMERE, "Deraumere"},
  {SIBUR, "Sibur"},
  {MENDIANE, "Mendiane"},
  {PHIRAS, "Phiras"},
  {THYSTAME, "Thystame"},
  {0, 0}
};

t_ressource	gl_food[] = {
  {HAMBURGER, "Hamburger"},
  {FISHBURGER, "Fishburger"},
  {CHEESEBURGER, "CHeeseburger"},
  {0, 0}
};
