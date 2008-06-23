/*
** get_rnd_action.c for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 13:49:46 2008 florent hochwelker
** Last update Wed May  7 23:15:06 2008 caner candan
*/

#include <stdlib.h>
#include "client.h"

static char	*actions[] =
  {"avance\n", "droite\n", "gauche\n", "voir\n", "inventaire\n",
   "prend objet\n", "pose objet\n", "expulse\n", "broadcast text\n",
   "incantation\n"};

char	*get_rnd_action()
{
  long	action;

  action = random() % NB_ACTIONS;
  return (actions[action]);
}
