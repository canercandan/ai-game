
#ifndef __ZAPPY_GRAPH_H__
# define __ZAPPY_GRAPH_H__

using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;

/* Define
*/

#define OBS_MAGIC		"OBS_MAGIC\n"

#define MODE_GRAPH		EDT_BURNINGSVIDEO
#define WIN_WEIGHT		640
#define WIN_HEIGHT		480
#define	MAP_HEIGHT		10
#define MAP_WEIGHT		10

#define NB_RESSOURCE		10

#define SOCK_ERROR		"ERROR : Can't connect !"


/* Files
*/

#define MAP_CASE_BMP		"bin/map/case.bmp"
#define MAP_CASE_JPG		"bin/map/case.jpg"

#define CUBE_SKY_UP		"bin/cube/up.tga"
#define CUBE_SKY_DN		"bin/cube/dn.tga"
#define CUBE_SKY_RT		"bin/cube/rt.tga"
#define CUBE_SKY_LF		"bin/cube/lf.tga"
#define CUBE_SKY_FT		"bin/cube/ft.tga"
#define CUBE_SKY_BK		"bin/cube/bk.tga"

/* Structure
*/

typedef struct		s_player
{
  char			*team;
  int			id;
  int			level;
  int			x;
  int			y;
  int			z;
  int			item[NB_RESSOURCE];
  char			*next;
}			t_player;

typedef struct		s_matrice
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
  int			sock;
}			t_window;

/* Function
*/

void	init_windows(t_window *w);
void	init_map(t_window *w);
void	init_matrix(t_window *w, t_matrix **m);

int	extract_num(char *buf, int num);

void	draw_all(t_window *w);
void	free_and_exit(t_window *w);

void	create_socket(int sock, char *name, char *port);
void	create_matrix(t_matrix **m, int size_x, int size_y);
void	create_map(t_window *w, int size_x, int size_y);

#endif
