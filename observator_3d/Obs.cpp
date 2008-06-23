//
// Obs.cpp for zappy in /home/aubry_j/zappy/observator_3d
// 
// Made by jordan aubry
// Login   <aubry_j@epitech.net>
// 
// Started on  Mon Jun 23 04:39:58 2008 jordan aubry
// Last update Mon Jun 23 04:40:00 2008 jordan aubry
//

#include <irrlicht.h>
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
  _texture[7] = _driver->getTexture(EGG);
  for (int i = 0; i <= 7; ++i)
    {
      if (_texture[i] == 0)
	{
	  std::cout << "Error loading texture. Be care run the observator 3D in his directory" << std::endl;
	  exit(0);
	}
    }
  _timer = this->_device->getTimer();
  _cursor = true;
}

void			Obs::Auth(Socket& socket)
{
  std::stringstream	ss;
  std::string		tmp;
  int			x, y;

  if (socket.recv(true) == "BIENVENUE\n")
    {
      socket.send(std::string(MAGIC_OBS) + "\n");
      ss << socket.recv(true);
      ss >> this->_x >> this->_y;// >> tmp;

      std::vector<Item>			v_item(NB_RESSOURCE);
      std::vector<std::vector<Item> >	v_y(this->_y, v_item);
      this->_item.assign(this->_x, v_y);

      std::vector<irr::core::vector3df>	v_vector3d(this->_y);
      this->_case.assign(this->_x, v_vector3d);

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
	    >> this->_item[x][y][6]._qte
	    >> this->_item[x][y][7]._qte;
	  tmp = ss.str().substr(ss.str().find_first_of("\n") + 1);
	  ss.clear();
	  ss.str("");
	  ss << tmp;
	  for (int i = 0; i < NB_RESSOURCE; i++)
	    if (this->_item[x][y][i]._qte > 0)
	      this->DrawItem(x, y, i);
	  if (this->_item[x][y][7]._qte > 0)
	    this->DrawEgg(x, y);
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
      tmp = ss.str().substr(sizeof(END_LIST_PLAYER) + ss.str().find(END_LIST_PLAYER));
      ss.clear();
      ss.str("");
      ss << tmp;
      ss >> tmp >> this->_time;
      std::cout << "LE TIME EST " << this->_time << std::endl;
      this->_time = 1 / this->_time * 1000;
      std::cout << "LE TIME EST " << this->_time << std::endl;
      this->DrawPlate();
    }
}

void				Obs::DrawEgg(int x, int y)
{
  this->_item[x][y][7]._img =
    this->GetScene()->addSphereSceneNode(5, 16, 0, -1,
					 irr::core::vector3df(COORD(y, this->GetY()), 17, COORD(x, this->GetX())),
					 irr::core::vector3df(0, 0, 0),
					 irr::core::vector3df(6, 8, 5));
  this->_item[x][y][7]._img->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  this->_item[x][y][7]._img->setMaterialTexture(0, this->GetDriver()->getTexture(EGG));
}

void				Obs::AddPlayer(std::stringstream& ss)
{
  std::string		tmp;
  Player*		player = new Player();
  int			isaBird;

  ss >> tmp >> isaBird
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
  if (isaBird)
    this->DeleteItem(player->_x, player->_y, 7);
}

void				Obs::DrawPlate()
{
  irr::scene::ISceneNode	*node;
  irr::scene::IAnimatedMesh	*palace;
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
	  this->_case[y][x] = node->getPosition();
	}
    }
  palace = this->_scene->getMesh(PALACE);
  node = this->_scene->addOctTreeSceneNode(palace->getMesh(0));
  node->setPosition(irr::core::vector3df((this->_y * 50 - 64), 1118, 650));
  node = this->_scene->addSphereSceneNode(5, 16, 0, -1,
					  irr::core::vector3df((this->_y * 50 - 164), -35, 0),
					  irr::core::vector3df(0, 0, 0),
					  irr::core::vector3df(500000, 0.1, 500000));
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node->setMaterialTexture(0, _driver->getTexture(MAP_FOND));
}

void					Obs::DrawAll(Socket &socket)
{
  std::map<int, Player*>::iterator	it, itErase;
  std::string				line;
  int					time = 0;
  int					action = 0;

  while (this->_device->run())
    {
      time = this->_timer->getRealTime();
      this->_driver->beginScene(false, true, 0);
      this->_scene->drawAll();
      this->_env->drawAll();
      this->_device->getGUIEnvironment()->drawAll();
      this->_driver->endScene();
      action = this->_timer->getRealTime();
      for (it = this->_player.begin(); it != this->_player.end(); ++it)
      	{
	  if (it->second->_anim != 0)
	    {
	      if (it->second->_anim <= action && it->second->_life == 1)
		{
		  it->second->_img->setFrameLoop(1, 159);
		  it->second->_anim = 0;
		}
	      if (it->second->_life == 0)
		{
		  if (it->second->_img->getFrameNr() == 791)
		    it->second->_img->setFrameLoop(791, 791);
		  if (it->second->_anim <= action)
		    {
		      this->_player.erase(it);
		      it->second->_img->remove();
		      it->second->~Player();
		    }
		}
	    }
	  if (it->second->_anim2 <= action)
	    {
	      it->second->_anim2 = 0;
	      it->second->_ps->remove();
	      it->second->_light->remove();
	    }
      	}
      line = socket.recv(false);
      if (line != "")
	this->ExecuteAction(line);
      time = this->_timer->getRealTime() - time;
      if (time < 50)
      	this->_device->sleep(50 - time);
    }
}

void					Obs::DrawPlayer(Player* player)
{
  player->_img = this->_scene->addAnimatedMeshSceneNode(this->_scene->getMesh(player->_skin[player->_id_team][0].c_str()));
  if (player->_img)
    {
      player->_img->setFrameLoop(1, 1);
      player->_img->setAnimationSpeed(40);
      player->_img->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      //       player->_img->setMaterialFlag(irr::video::EMF_BILENEAR_FILTER, false);
      //       player->_img->setMaterialFlag(irr::video::EMF_TRILNEAR_FILTER, false);
      //       player->_img->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, false);
      player->_img->setPosition(irr::core::vector3df(Y(player->_y), 0, X(player->_x)));
      player->_img->setMaterialTexture(0, this->_driver->getTexture(player->_skin[player->_id_team][player->_lvl].c_str()));
      if (player->_z == NORTH)
	player->_z = OBS_NORTH;
      else if (player->_z == EAST)
	player->_z = OBS_EAST;
      else if (player->_z == WEST)
	player->_z = OBS_WEST;
      else
	player->_z = OBS_SOUTH;
      player->_img->setRotation(irr::core::vector3df(0, player->_z, 0));
      player->_anim = 1;
      player->_life = 1;
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
  Action		action(this);
  std::stringstream	ss;
  int			id, idx_action, x, y, type;
  std::string		param;

  std::cout << "J'ai recu = [" << line  << "]" << std::endl;
  while (!line.empty())
    {
      ss.clear();
      ss.str("");
      if (line.substr(0, line.find_first_of(" ")) == "ADD_CLIENT")
	{
	  ss << line;
	  this->AddPlayer(ss);
	}
      else if (line.substr(0, line.find_first_of(" ")) == NEW_ITEM)
	{
	  ss << line;
	  ss >> param >> x >> y >> type;
	  if (++this->_item[x][y][type]._qte == 1)
	    this->DrawItem(x, y, type);
	  //	  std::cout << "Hop les pierres sont dispersee." << std::endl;
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
