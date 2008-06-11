//
// Obs.cpp for Obs3D in /home/hochwe_f/zappy/observator_3d
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Fri Jun  6 13:59:02 2008 florent hochwelker
// Last update Wed Jun 11 19:35:14 2008 jordan aubry
//

#include <sstream>
#include <vector>
#include "Obs.h"
#include "Item.h"
#include "Action.h"
#include "observator_3d.h"
#include "common.h"

Obs::Obs(int ac, char **av)
{
  if (ac > 2)
    {
      _host = av[1];
      std::stringstream	ss(av[2]);
      ss >> _port;
    }
  else
    {
      _host = DEFAULT_HOST;
      _port = DEFAULT_PORT;
    }
  _texture[0] = _driver->getTexture(ITEM_1);
  _texture[1] = _driver->getTexture(ITEM_2);
  _texture[2] = _driver->getTexture(ITEM_3);
  _texture[3] = _driver->getTexture(ITEM_4);
  _texture[4] = _driver->getTexture(ITEM_5);
  _texture[5] = _driver->getTexture(ITEM_6);
  //_texture[6] = _driver->getTexture(FOOD);
  _texture[7] = _driver->getTexture(EGG);
}

void		Obs::Auth(Socket& socket)
{
  std::stringstream	ss;
  std::string		tmp;
  int			x, y;

  if (socket.recv(true) == "BIENVENUE\n")
    {
      socket.send(std::string(MAGIC_OBS) + "\n");
      ss << socket.recv(true);
      ss >> this->_x >> this->_y >> tmp;
      std::vector<Item>			v_item(NB_RESSOURCE);
      std::vector<std::vector<Item> >	v_y(this->_y, v_item);

      this->_item.assign(this->_x, v_y);

      if (tmp == START_LIST_ITEM)
	{
	  while (ss.str().find(END_LIST_ITEM) == std::string::npos)
	    ss << socket.recv(true);
	  tmp = ss.str().substr(sizeof(START_LIST_ITEM) + ss.str().find(START_LIST_ITEM));
	  ss.str("");
	  ss << tmp;
	  while (tmp.find(END_LIST_ITEM) != 0)
	    {
	      ss >> x >> y;
	      ss
		>> this->_item[x][y][0]._qte
		>> this->_item[x][y][1]._qte
		>> this->_item[x][y][2]._qte
		>> this->_item[x][y][3]._qte
		>> this->_item[x][y][4]._qte
		>> this->_item[x][y][5]._qte
		>> this->_item[x][y][6]._qte;
	      tmp = ss.str().substr(ss.str().find_first_of("\n") + 1);
	      ss.clear();
	      ss.str("");
	      ss << tmp;
	      for (int i = 0; i < NB_RESSOURCE; i++)
		if (this->_item[x][y][i]._qte > 0)
		  this->DrawItem(x, y, i);
	    }
	  ss.clear();
	  ss.str("");
	  ss << tmp;
	  while (ss.str().find(END_LIST_PLAYER) == std::string::npos)
	    ss << socket.recv(true);
	  tmp = ss.str().substr(sizeof(START_LIST_PLAYER) + ss.str().find(START_LIST_PLAYER));
	  ss.clear();
	  ss.str("");
	  ss << tmp;
	  while (tmp.find(END_LIST_PLAYER) != 0)
	    {
	      this->AddPlayer(ss);
	      tmp = ss.str().substr(ss.str().find_first_of("\n") + 1);
	      ss.clear();
	      ss.str("");
	      ss << tmp;
	    }
	}
      this->DrawPlate();
    }
}

void				Obs::AddPlayer(std::stringstream& ss)
{
  std::string	tmp;
  Player* player = new Player();

  ss >> tmp
     >> player->_id
     >> player->_team
     >> player->_id_team
     >> player->_lvl
     >> player->_x
     >> player->_y
     >> player->_z
     >> player->_inventory[0]
     >> player->_inventory[1]
     >> player->_inventory[2]
     >> player->_inventory[3]
     >> player->_inventory[4]
     >> player->_inventory[5]
     >> player->_inventory[6];
  this->DrawPlayer(player);
  this->_player[player->_id] = player;
}

void				Obs::DrawPlate()
{
  irr::scene::ISceneNode	*node;
  int				x;
  int				y;

  for (x = 0; x < this->_x; x++)
    {
      for (y = 0; y < this->_y; y++)
	{
	  node = _scene->addCubeSceneNode();
	  node->setScale(irr::core::vector3df(10, 1, 10));
	  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  node->setMaterialTexture(0, _driver->getTexture(MAP_CASE));
	  node->setPosition(irr::core::vector3df(CASEX(x), -29, CASEY(y)));
	}
    }
}

void		Obs::DrawAll(Socket &socket)
{
  irr::ITimer	*timer = this->_device->getTimer();
  std::string	line;
  int		time;

  while (this->_device->run())
    {
      time = timer->getRealTime();
      _driver->beginScene(false, true, 0);
      _scene->drawAll();
      _env->drawAll();
      _device->getGUIEnvironment()->drawAll();
      _driver->endScene();
      line = socket.recv(false);
      if (line != "")
	this->ExecuteAction(line);
      time = timer->getRealTime() - time;
      if (time < 50)
	this->_device->sleep(50 - time);
    }
}

void					Obs::DrawPlayer(Player* player)
{
  player->_img = this->_scene->addAnimatedMeshSceneNode(this->_scene->getMesh(INVADER));
  if (player->_img)
    {
      player->_img->setFrameLoop(1, 1);
      player->_img->setAnimationSpeed(0);
      player->_img->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      player->_img->setPosition(irr::core::vector3df(Y(player->_y), 0, X(player->_x)));
      player->_img->setMaterialTexture(0, this->_driver->getTexture(SKIN_1));
      if (player->_z == NORTH)
	player->_z = OBS_NORTH;
      else if (player->_z == EAST)
	player->_z = OBS_EAST;
      else if (player->_z == WEST)
	player->_z = OBS_WEST;
      else
	player->_z = OBS_SOUTH;
      player->_img->setRotation(irr::core::vector3df(0, player->_z, 0));
    }
}

void		Obs::DrawItem(int x, int y, int type)
{
  this->_item[x][y][type]._img = this->_scene->addSphereSceneNode();
  if (this->_item[x][y][type]._img)
    {
      this->_item[x][y][type]._img->setScale(irr::core::vector3df(1, 1, 1));
      this->_item[x][y][type]._img->setPosition(irr::core::vector3df(ItemY(y, type), -20, ItemX(x, type)));
      this->_item[x][y][type]._img->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      if (type != NOURRITURE)
	this->_item[x][y][type]._img->setMaterialTexture(0, this->_texture[type]);
    }
}

void		Obs::DeleteItem(int x, int y, int type)
{
  if (--this->_item[x][y][type]._qte == 0)
    this->_item[x][y][type]._img->remove();
}

void		Obs::ExecuteAction(std::string& line)
{
  Action	action(this);
  std::stringstream	ss;
  int			id, idx_action,;
  std::string		param;

  while (!line.empty())
    {
      ss.clear();
      ss.str("");
      if (line.substr(0, line.find_first_of(" ")) == "ADD_CLIENT")
	{
	  ss << line;
	  this->AddPlayer(ss);
	}
      else
	{
	  ss << line;
	  ss >> id >> idx_action >> param;
	  std::cout << "Execution de " << idx_action << " par " << id << std::endl;
	  action.ApplyAction(this->_player[id], idx_action, param);
	}
      line = line.substr(line.find_first_of("\n") + 1);
    }
}
