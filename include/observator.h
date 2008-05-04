/*
** observator.h for zappy in /home/aubry_j/zappy/include
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Fri May  2 17:54:35 2008 jordan aubry
** Last update Sun May  4 13:57:28 2008 jordan aubry
*/

#ifndef __OBSERVATOR_H__
# define __OBSERVATOR_H__

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

/* Define
*/

#define OBS_MAGIC		"OBS_MAGIC\n"
#define OBS_USAGE		"Usage :\n./observator (host) (port)\n"
#define OBS_CASE		192

#define MODE_GRAPH		EDT_BURNINGSVIDEO
#define FAR_VALUE		100000
#define WIN_WEIGHT		640
#define WIN_HEIGHT		480

#define NB_RESSOURCE		10

#define SOCK_ERROR		"ERROR : Can't connect !"


/* Files
*/

#define MAP_CASE_BSP		"maps/case.bsp"

#define SKY_UP			"env/up.tga"
#define SKY_DN			"env/dn.tga"
#define SKY_RT			"env/rt.tga"
#define SKY_LF			"env/lf.tga"
#define SKY_FT			"env/ft.tga"
#define SKY_BK			"env/bk.tga"

/* Structure
*/

typedef struct		s_matrix
{
  int			move;
  int			level;
  int			item[NB_RESSOURCE];
}			t_matrix;

typedef struct		s_window
{
  IrrlichtDevice	*device;
  IVideoDriver		*driver;
  ISceneManager		*smgr;
  IGUIEnvironment	*env;
  ICameraSceneNode	*camera;
  ITerrainSceneNode	*map;
}			t_window;

typedef struct		s_obs
{
  t_window		*window;
  t_matrix		**matrix;
  int			x;
  int			y;
  int			sock;
}			t_obs;

/* Function
*/

void		main_usage();

t_obs		*init_obs();
t_window	*init_window();
t_matrix	**init_matrix(t_obs *obs);
void		init_map_size(t_obs *obs);
void		init_case(t_obs *obs);
void		init_socket(t_obs *obs, char *name, char *port);
int		extract_num(char *buf, int num);

void		draw_all(t_obs *obs);
void		free_obs(t_obs *obs);

#endif
