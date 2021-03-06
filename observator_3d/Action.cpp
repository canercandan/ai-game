//
// Action.cpp for Obs3D in /home/hochwe_f/zappy/observator_3d
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Mon Jun  9 19:15:28 2008 florent hochwelker
// Last update Tue Jun 24 11:19:16 2008 florent hochwelker
//

#include <irrlicht.h>
#include <sstream>
#include "common.h"
#include "Action.h"
#include "Obs.h"

typedef void	(Action::*f)(Player*, std::string& param);

Action::Action(Obs* obs)
{
  _obs = obs;
  _map[UP] = &Action::ActionUp;
  _map[RIGHT] = &Action::ActionRight;
  _map[LEFT] = &Action::ActionLeft;
  _map[SEE] = &Action::ActionSee;
  _map[INVENTORY] = &Action::ActionInventory;
  _map[TAKE_OBJ] = &Action::ActionTakeObj;
  _map[DROP_OBJ] = &Action::ActionDropObj;
  _map[KICK] = &Action::ActionKick;
  _map[BROADCAST] = &Action::ActionBroadcast;
  _map[LEVELUP_PROGRESS] = &Action::ActionLevelUpProgress;
  _map[LEVELUP] = &Action::ActionLevelUp;
  _map[FORK] = &Action::ActionFork;
  _map[COUNT] = &Action::ActionCount;
  _map[BIRD] = &Action::ActionBird;
  _map[DEATH] = &Action::ActionDeath;
}

void	Action::ApplyAction(Player* player, int idx, std::string& param)
{
  if (this->_map.count(idx) > 0 && player && player->_life > 0)
    ((*this).*(this->_map[idx]))(player, param);
}

void		Action::MovePlayer(Player* player, int x, int y)
{
  irr::scene::ISceneNodeAnimator*   anim;

  if (ABS(player->_x - x) > 1 || ABS(player->_y - y) > 1)
    {
      anim = this->_obs->GetScene()->createFlyStraightAnimator(irr::core::vector3df(COORD(player->_y, this->_obs->GetY()), 0, COORD(player->_x, this->_obs->GetX())),
                                                               irr::core::vector3df(COORD(y, this->_obs->GetY()), 0, COORD(x, this->_obs->GetX())),
                                                               0, false);
      player->_img->setFrameLoop(1, 159);
    }
  else
    {
      anim = this->_obs->GetScene()->createFlyStraightAnimator(irr::core::vector3df(COORD(player->_y, this->_obs->GetY()), 0, COORD(player->_x, this->_obs->GetX())),
							       irr::core::vector3df(COORD(y, this->_obs->GetY()), 0, COORD(x, this->_obs->GetX())),
							       static_cast<int>(this->_obs->GetTime() + 1), false);
      player->_img->setFrameLoop(160, 183);
    }
  player->_img->addAnimator(anim);
  player->_x = x;
  player->_y = y;
  player->_anim = this->_obs->GetRealTime() + this->_obs->GetTime();
  anim->drop();
}

void		Action::ActionUp(Player* player, std::string&)
{
  //  std::cout << "Je suis bien dans ActionUp" << std::endl;
  //  std::cout << "Ma direction est: " << player->_z << std::endl;
  switch (player->_z)
    {
    case OBS_NORTH:
      this->MovePlayer(player, player->_x, (player->_y == 0) ? this->_obs->GetY() - 1 : player->_y - 1);
      break;
    case OBS_EAST:
      this->MovePlayer(player, (player->_x == this->_obs->GetX() - 1) ? 0 : player->_x + 1, player->_y);
      break;
    case OBS_WEST:
      this->MovePlayer(player, (player->_x == 0) ? this->_obs->GetX() - 1 : player->_x - 1, player->_y);
      break;
    case OBS_SOUTH:
      this->MovePlayer(player, player->_x, (player->_y == this->_obs->GetY() - 1) ? 0 : player->_y + 1);
      break;
    }
}

void		Action::ActionRight(Player* player, std::string&)
{
  player->_z += 90;
  if (player->_z > 270)
    player->_z = 0;
  player->_img->setRotation(irr::core::vector3df(player->_y, player->_z ,player->_x));
}

void		Action::ActionLeft(Player* player, std::string&)
{
  player->_z -= 90;
  if (player->_z < 0)
    player->_z = 270;
  player->_img->setRotation(irr::core::vector3df(player->_y, player->_z ,player->_x));
}

void		Action::ActionTakeObj(Player* player, std::string& param)
{
  std::stringstream	ss(param);
  int			idx;

  ss >> idx;
  this->_obs->DeleteItem(player->_x, player->_y, idx);
  player->_inventory[idx]++;
  player->_img->setFrameLoop(532, 548);
  player->_anim = this->_obs->GetRealTime() + this->_obs->GetTime();
}

void		Action::ActionDropObj(Player* player, std::string& param)
{
  std::stringstream	ss(param);
  int			idx;

  ss >> idx;
  if (++this->_obs->_item[player->_x][player->_y][idx]._qte == 1)
    this->_obs->DrawItem(player->_x, player->_y, idx);
  player->_inventory[idx]--;
  player->_img->setFrameLoop(532, 548);
  player->_anim = this->_obs->GetRealTime() + this->_obs->GetTime();
}

void		Action::ActionFork(Player* player, std::string&)
{
  if (++this->_obs->_item[player->_x][player->_y][7]._qte == 1)
    this->_obs->DrawEgg(player->_x, player->_y);
}

void		Action::ActionBird(Player*, std::string&)
{
  std::cout << "On a un nouveau dans la famille !" << std::endl;
}

void		Action::ActionLevelUpProgress(Player* player, std::string&)
{
  player->_img->setFrameLoop(263, 286);
  player->_anim = this->_obs->GetRealTime() + 300 * this->_obs->GetTime();
}

void		 Action::ActionKick(Player* player, std::string&)
{
  player->_img->setFrameLoop(336, 383);
  player->_anim = this->_obs->GetRealTime() + this->_obs->GetTime();
  std::map<int, Player*>::iterator	it = this->_obs->_player.begin();
  std::map<int, Player*>::iterator	it_end = this->_obs->_player.end();
  for (;it != it_end; ++it)
    if (it->second->_x == player->_x
	&& it->second->_y == player->_y
	&& player != it->second)
      {
	switch (player->_z)
	  {
	  case OBS_NORTH:
	    this->MovePlayer(it->second, it->second->_x, (it->second->_y == 0) ? this->_obs->GetY() - 1 : it->second->_y - 1);
	    break;
	  case OBS_EAST:
	    this->MovePlayer(it->second, (it->second->_x == this->_obs->GetX() - 1) ? 0 : it->second->_x + 1, it->second->_y);
	    break;
	  case OBS_WEST:
	    this->MovePlayer(it->second, (it->second->_x == 0) ? this->_obs->GetX() - 1 : it->second->_x - 1, it->second->_y);
	    break;
	  case OBS_SOUTH:
	    this->MovePlayer(it->second, it->second->_x, (it->second->_y == this->_obs->GetY() - 1) ? 0 : it->second->_y + 1);
	    break;
	  }
      }
}

void		Action::ActionDeath(Player* player, std::string&)
{
  player->_img->setFrameLoop(778, 791);
  player->_img->setLoopMode(false);
  player->_life = 0;
  player->_anim = this->_obs->GetRealTime() + 100 * this->_obs->GetTime();
}

void            Action::ActionSee(Player*, std::string&)		{}
void            Action::ActionCount(Player*, std::string&)		{}

void            Action::ActionLevelUp(Player* player, std::string& param)
{
  if (player)
    {
      player->_img->setFrameLoop(1, 159);
      player->_anim = 0;

      if (param == "1")
	{
	  for (int i = 0; i < 6; ++i)
	    if (this->_obs->_item[player->_x][player->_y][i]._qte > 0)
	      {
		this->_obs->_item[player->_x][player->_y][i]._qte == 0;
		this->_obs->DeleteItem(player->_x, player->_y, i);
	      }
	  std::map<int, Player*>::iterator	it = this->_obs->_player.begin();
	  std::map<int, Player*>::iterator	it_end = this->_obs->_player.end();
	  for (;it != it_end; ++it)
	    if (it->second->_x == player->_x && it->second->_y == player->_y)
	      {
		irr::scene::ISceneNodeAnimator*   anim = this->_obs->GetScene()->
		  createFlyCircleAnimator(irr::core::vector3df(COORD(player->_y, this->_obs->GetY()), 0, COORD(player->_x, this->_obs->GetX())), 20, 0.01);
		++(it->second->_lvl);
		it->second->_img->setMaterialTexture(0, this->_obs->GetDriver()->getTexture(it->second->_skin[it->second->_id_team][it->second->_lvl].c_str()));
		it->second->_light = this->_obs->GetScene()->addLightSceneNode();
		it->second->_light->addAnimator(anim);
		it->second->_ps = this->_obs->GetScene()->addParticleSystemSceneNode(false, it->second->_light);
		it->second->_ps->setParticleSize(irr::core::dimension2d<float>(5, 5));
		irr::scene::IParticleEmitter*     pem = it->second->_ps->createBoxEmitter(irr::core::aabbox3d<float>(-3, 0, -3, 4, 4, 4),
											  irr::core::vector3df(0, 0.03, 0), 100, 100,
											  irr::video::SColor(0, 255, 255, 255),
											  irr::video::SColor(0, 255, 255, 255), 400, 1000);
		it->second->_ps->setEmitter(pem);
		irr::scene::IParticleAffector*    paf = it->second->_ps->createFadeOutParticleAffector();
		it->second->_ps->addAffector(paf);
		it->second->_ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		it->second->_ps->setMaterialTexture(0, this->_obs->GetDriver()->getTexture(FIRE));
		it->second->_ps->setMaterialType(irr::video::EMT_TRANSPARENT_VERTEX_ALPHA);
		it->second->_anim2 = this->_obs->GetRealTime() + 10 * this->_obs->GetTime();
		anim->drop();
		paf->drop();
		pem->drop();
	      }
	}
    }
}

void            Action::ActionBroadcast(Player* player, std::string&)
{
  player->_img->setFrameLoop(448, 491);
  player->_anim = this->_obs->GetRealTime() + this->_obs->GetTime();
}

void            Action::ActionInventory(Player*, std::string&)		{}
