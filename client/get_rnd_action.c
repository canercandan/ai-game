/*
** get_rnd_action.c for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 13:49:46 2008 florent hochwelker
** Last update Tue Apr 22 14:11:20 2008 florent hochwelker
*/

#include <stdlib.h>

char	*get_rnd_action()
{
  long	i;

  i = random() % 10;
  switch (i)
    {
    case 0:
      return ("avance\n");
    case 1:
      return ("droite\n");
    case 2:
      return ("gauche\n");
    case 3:
      return ("voir\n");
    case 4:
      return ("inventaire\n");
    case 5:
      return ("prend objet\n");
    case 6:
      return ("pose objet\n");
    case 7:
      return ("expulse\n");
    case 8:
      return ("broadcast text\n");
    case 9:
      return ("incantation\n");
    default:
      return ("wtf\n");
    }
}
