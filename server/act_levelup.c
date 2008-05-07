/*
** act_levelup.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Wed May  7 20:27:39 2008 caner candan
*/

#include "server.h"
#include "common.h"

static t_level		level[] = {
  {2, 1},
  {3, 2},
  {4, 2},
  {5, 4},
  {6, 4},
  {7, 6},
  {8, 6},
  {0, 0}
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
  mask_res = 0;
  while (ressources)
    {
      mask_res += PWR(((t_ressource *) ressources->data)->idx);
      ressources = ressources->next;
    }
  if (mask_res != mask_ressources(client))
    return (-1);
  return (0);
}

static void	levelup(t_client *client, t_info *info)
{
  t_list	*t;
  t_client	*c;
  void		*data;
  int		x;
  int		y;

  t = info->zone[client->x][client->y].clients;
  while (t)
    {
      c = t->data;
      if (c->level <= MAX_LEVEL)
	{
	  c->level++;
	  send_buf_to_client(c, OK);
	}
      else
	send_buf_to_client(c, KO);
      t = t->next;
    }
  while ((data = pop_list(&(info->zone[client->x][client->y].ressources))))
    {
      x = get_random(info->x, client->x);
      y = get_random(info->y, client->y);
      push_list(&(info->zone[x][y].ressources), data);
    }
}

int		act_levelup(char *param, t_client *client, t_info *info)
{
  (void)param;
  send_buf_to_client(client, LVLUP_PROCESS);
  if (has_players(info, client) < 0 ||
      has_ressources(info, client) < 0)
    {
      send_buf_to_client(client, KO);
      return (-1);
    }
  levelup(client, info);
  return (0);
}
