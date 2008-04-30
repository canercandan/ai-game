/*
** list_ressources.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:05:04 2008 majdi toumi
** Last update Wed Apr 30 19:20:42 2008 majdi toumi
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
