/*
** is_levelup.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May  5 08:50:26 2008 caner candan
** Last update Mon May  5 17:15:35 2008 caner candan
*/

#include "server.h"
#include "common.h"

static t_level	level[] = {
  {1, 0, NULL},
  {2, 1, NULL},
  {3, 2, NULL},
  {4, 2, NULL},
  {5, 4, NULL},
  {6, 4, NULL},
  {7, 6, NULL},
  {8, 6, NULL},
  {0, 0, 0}
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
  {7, SIBUR, 3},
  {7, PHIRAS, 1},
  {8, LINEMATE, 2},
  {8, DERAUMERE, 2},
  {8, SIBUR, 2},
  {8, MENDIANE, 2},
  {8, PHIRAS, 2},
  {8, THYSTAME, 1},
  {0, 0, 0}
};

static int	has_players(t_info *info, t_client *client)
{
  int		nb;
  int		i;

  nb = count_list(info->zone[client->x][client->y].clients);
  for (i = 0; level[i].lvl; i++)
    if (level[i].lvl == client->level + 1)
      {
	if (level[i].nb_client == nb)
	  return (0);
	return (-1);
      }
  return (-1);
}

static int	mask_ressources(t_client *client)
{
  int		res;
  int		i;

  res = 0;
  for (i = 0; critere[i].lvl; i++)
    if (critere[i].lvl == client->level + 1)
      res += PWR(critere[i].idx_ressource) * critere[i].qte;
  return (res);
}

static int	has_ressources(t_info *info, t_client *client)
{
  t_list	*ressources;
  int		mask_res;

  ressources = info->zone[client->x][client->y].ressources;
  while (ressources)
    {
      mask_res += PWR(((t_ressource *) ressources->data)->idx);
      ressources = ressources->next;
    }
  if (mask_res != mask_ressources(client))
    return (-1);
  return (0);
}

int		is_levelup(t_info *info, t_client *client)
{
  t_list	*clients;

  if (has_players(info, client) < 0)
    return (-1);
  if (has_ressources(info, client) < 0)
    return (-1);
  clients = info->clients;
  while (clients)
    clients = clients->next;
  return (0);
}
