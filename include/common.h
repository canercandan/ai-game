/*
** common.h for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sun May  4 14:46:59 2008 florent hochwelker
** Last update Wed May  7 10:46:19 2008 caner candan
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
# define OK		"ok\n"
# define KO		"ko\n"
# define DEAD		"mort\n"
# define LVLUP_PROCESS	"elevation en cours\n"
# define MESSAGE	"message "
# define KICKIT		"deplacement "

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
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NOURRITURE
  }	t_idx_ressource;

#endif /* !__COMMON_H__ */
