/*
** common.h for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sun May  4 14:46:59 2008 florent hochwelker
** Last update Mon May  5 16:00:27 2008 majdi toumi
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
# define OK	"ok\n"
# define KO	"ko\n"

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
    HAMBURGER
  }	t_idx_ressource;

#endif /* !__COMMON_H__ */
