/*
** common.h for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sun May  4 14:46:59 2008 florent hochwelker
** Last update Mon Jun  9 14:17:53 2008 florent hochwelker
*/

#ifndef __COMMON_H__
# define __COMMON_H__

# define MAGIC_OBS	"OBS_CLIENT"

/*
** Exits, debug and errors
*/
# define DEBUG			0
# define EXIT_SUCC		0
# define EXIT_FAIL		42

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
# define LVLUP_OK	"niveau actuel : "

/*
** Default's values
*/
# define DEFAULT_HOST		"localhost"
# define DEFAULT_PORT		12345
# define TCP			"tcp"

/*
** List OBS
*/
# define START_LIST_ITEM	"LIST_ITEM"
# define END_LIST_ITEM		"END_LIST_ITEM"
# define START_LIST_PLAYER	"LIST_PLAYER"
# define END_LIST_PLAYER	"END_LIST_PLAYER"

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

/*
** Enum action
*/
enum
  {
    UP,
    RIGHT,
    LEFT,
    SEE,
    INVENTORY,
    TAKE_OBJ,
    DROP_OBJ,
    KICK,
    BROADCAST,
    LEVELUP_PROGRESS,
    LEVELUP,
    FORK,
    COUNT,
    BIRD,
    DEATH
  };

#endif /* !__COMMON_H__ */
