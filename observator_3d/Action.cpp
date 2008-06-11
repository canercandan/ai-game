//
// Action.cpp for Obs3D in /home/hochwe_f/zappy/observator_3d
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Mon Jun  9 19:15:28 2008 florent hochwelker
// Last update Wed Jun 11 19:41:03 2008 jordan aubry
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
  ((*this).*(this->_map[idx]))(player, param);
}

void		Action::MovePlayer(Player* player, int x, int y)
{
  if (ABS(player->_x - x) > 1 || ABS(player->_y - y) > 1)
    {
      player->_x = x;
      player->_y = y;
      player->_img->setPosition(irr::core::vector3df(COORD(player->_y, this->_obs->GetY()), 0, COORD(player->_x, this->_obs->GetX())));
    }
  else
    {
      irr::scene::ISceneNodeAnimator*	anim;

      anim = this->_obs->GetScene()->createFlyStraightAnimator(irr::core::vector3df(COORD(player->_y, this->_obs->GetY()), 0, COORD(player->_x, this->_obs->GetX())),
							       irr::core::vector3df(COORD(y, this->_obs->GetY()), 0, COORD(x, this->_obs->GetX())),
							       1000, false);
      player->_x = x;
      player->_y = y;
      player->_img->setFrameLoop(160, 183);
      player->_img->addAnimator(anim);
      player->_img->setFrameLoop(1, 1);
      anim->drop();
    }
}

void		Action::ActionUp(Player* player, std::string&)
{
  std::cout << "Je suis bien dans ActionUp" << std::endl;
  std::cout << "Ma direction est: " << player->_z << std::endl;
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

void		Action::ActionSee(Player*, std::string&)
{
}

void		Action::ActionInventory(Player*, std::string&)
{
}

void		Action::ActionTakeObj(Player* player, std::string& param)
{
  std::stringstream	ss(param);
  int			idx;

  ss >> idx;
  this->_obs->DeleteItem(player->_x, player->_y, idx);
  player->_inventory[idx]++;
}

void		Action::ActionDropObj(Player* player, std::string& param)
{
  std::stringstream	ss(param);
  int			idx;

  ss >> idx;
  if (++this->_obs->_item[player->_x][player->_y][idx]._qte == 1)
    this->_obs->DrawItem(player->_x, player->_y, idx);
  player->_inventory[idx]--;
}

void		Action::ActionKick(Player* player, std::string&)
{
  (void) player;
}

void		Action::ActionBroadcast(Player* player, std::string&)
{
  (void) player;
}

void		Action::ActionLevelUpProgress(Player* player, std::string&)
{
  (void) player;
}

void		Action::ActionLevelUp(Player* player, std::string&)
{
  (void) player;
}

void		Action::ActionFork(Player* player, std::string&)
{
  this->_obs->_item[player->_x][player->_y][7]._img =
    this->_obs->GetScene()->addSphereSceneNode(5, 16, 0, -1,
					   irr::core::vector3df(COORD(player->_x, this->_obs->GetX()), 35, COORD(player->_y, this->_obs->GetY())),
					   irr::core::vector3df(0, 0, 0),
					   irr::core::vector3df(6, 8, 5));
  this->_obs->_item[player->_x][player->_y][7]._img->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  this->_obs->_item[player->_x][player->_y][7]._img->setMaterialTexture(0, this->_obs->_texture[7]);
}

void		Action::ActionCount(Player* player, std::string&)
{
  (void) player;
}

void		Action::ActionBird(Player* player, std::string&)
{
  (void) player;
}

void		Action::ActionDeath(Player* player, std::string&)
{
  (void) player;
}
