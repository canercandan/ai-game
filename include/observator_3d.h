/*
** observator.h for zappy in /home/aubry_j/zappy/include
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Fri May  2 17:54:35 2008 jordan aubry
** Last update Thu Jun  5 18:09:49 2008 florent hochwelker
*/

#ifndef __OBSERVATOR_3D_H__
# define __OBSERVATOR_3D_H__

/* Define general
*/

#define OBS_USAGE		"Usage : ./observator (host) (port)\n"
#define OBS_CASE		192

#define MODE_GRAPH		EDT_BURNINGSVIDEO
#define FAR_VALUE		100000
#define WIN_WEIGHT		640
#define WIN_HEIGHT		480
#define	CAMERA_SPEED		100

#define NB_RESSOURCE		7

#define SOCK_ERROR		"ERROR : Can't connect !\n"

/* Define 3d
*/
#define OBS_NORTH		180
#define OBS_SOUTH		0
#define OBS_EAST		270
#define OBS_WEST		90

/*
** Files
*/
#define OBS_PK3		"bin/map.pk3"

#define SKY_UP		"env/up.tga"
#define SKY_DN		"env/dn.tga"
#define SKY_RT		"env/rt.tga"
#define SKY_LF		"env/lf.tga"
#define SKY_FT		"env/ft.tga"
#define SKY_BK		"env/bk.tga"

#define MAP_CASE	"maps/case.bmp"

/*
** Item's defines
*/
#define ITEM_1	"textures/water.bmp"
#define ITEM_2	"textures/gold.bmp"
#define ITEM_3	"textures/brown.bmp"
#define ITEM_4	"textures/purple.bmp"
#define ITEM_5	"textures/grass.bmp"
#define ITEM_6	"textures/lava.bmp"

#define	INVADER			"models/perso.md2"
#define	SKIN_1			"models/alien.bmp"

/*
** Casts macros
*/
#define DEVICE(data)	((IrrlichtDevice *) (data))
#define DRIVER(data)	((IVideoDriver *) (data))
#define MANAGER(data)	((ISceneManager *) (data))
#define	ENV(data)	((IGUIEnvironment *) (data))
#define CAMERA(data)	((ICameraSceneNode *) (data))
#define TERRAIN(data)	((ITerrainSceneNode *) (data))
#define TEXTURE(data)	((ITexture *) (data))

#define	ISN(data)	((ISceneNode *) (data))

/*
** Get x/y
*/
#define X(data)		((data * 100) - ((obs->x + 1) * 50))
#define Y(data)		((data * 100) - ((obs->y + 1) * 50))

#define CASEX(data)	(((data + 1) * 100) - ((obs->x + 1) * 50))
#define CASEY(data)	(((data + 1) * 100) - ((obs->y + 1) * 50))

/*
** Structures
*/

typedef struct	s_matrix
{
  int		move;
  int		level;
  int		item[NB_RESSOURCE];
  void		*rock[NB_RESSOURCE];
}		t_matrix;

typedef struct	s_window
{
  void		*device;
  void		*driver;
  void		*smgr;
  void		*env;
  void		*camera;
  void		*map;
}		t_window;

typedef struct	s_item
{
  void		*img;
  int		x;
  int		y;
  int		z;
}		t_item;

typedef struct	s_player
{
  char		*team;
  int		id;
  int		x;
  int		y;
  int		case_x;
  int		case_y;
  int		life;
  int		inventory[NB_RESSOURCE];
}		t_player;

typedef struct	s_obs
{
  char		*host;
  int		port;
  int		sock;
  t_window	*window;
  t_matrix	**matrix;
  t_player	*player;
  t_item	item[NB_RESSOURCE];
  int		x;
  int		y;
}		t_obs;

// Functions

void		main_usage(void);
int		parse_args(int ac, char **av, t_obs *obs);

// Init's functions

void		init_obs(t_obs *obs);
t_window	*init_window(void);
t_matrix	**init_matrix(t_obs *obs);
void		init_item(t_obs *obs);
void		init_map_size(t_obs *obs);
void		init_case(t_obs *obs);
void		init_socket(t_obs *obs);

int		extract_num(char *buf, int num);

void		msg_reception(t_obs *obs);

void		draw_all(t_obs *obs);
void		draw_rock(t_obs *obs, int x, int y, int type);
void		draw_player(t_obs *obs, int x, int y, int z);

void		rm_rock(t_obs *obs, int x, int y, int type);

void		free_obs(t_obs *obs);

#endif
