/*
** common.h for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sun May  4 14:46:59 2008 florent hochwelker
** Last update Sun May  4 15:36:19 2008 jordan aubry
*/

#ifndef __COMMON_H__
# define __COMMON_H__

# define MAGIC_OBS	"OBS_CLIENT"

/*
** Command's defines
*/
# define START_CMD	"{"
# define END_CMD	"}\n"
# define SEPARATOR_CMD	","
# define SEPARATOR_ELM	" "

/*
** Messages
*/
# define OK	"OK\n"
# define KO	"KO\n"

/*
** Directions
*/
typedef enum
  {
    NORTH,
    EAST,
    SOUTH,
    WEST
  }	t_direction;

/*
** Ressources' enum
*/
typedef enum
  {
    LINEMATE = 1,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    HAMBURGER,
    FISHBURGER,
    CHEESEBURGER
  }	t_idx_ressource;

#endif /* !__COMMON_H__ */
