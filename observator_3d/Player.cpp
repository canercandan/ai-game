//
// Player.cpp for Obs3D in /home/hochwe_f/zappy/observator_3d
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Fri Jun  6 19:55:06 2008 florent hochwelker
// Last update Tue Jun 17 22:45:11 2008 jordan aubry
//

#include <irrlicht.h>
#include <string>
#include <vector>
#include "Player.h"

Player::Player() : _inventory(NB_RESSOURCE, 0)
{
  _anim = 0;
  _anim2 = 0;

  std::vector<std::string>			_str(9);
  _skin.assign(5, _str);

  _skin[0][0] = INVADER;
  _skin[0][1] = INVADER_1;
  _skin[0][2] = INVADER_2;
  _skin[0][3] = INVADER_3;
  _skin[0][4] = INVADER_4;
  _skin[0][5] = INVADER_5;
  _skin[0][6] = INVADER_6;
  _skin[0][7] = INVADER_7;
  _skin[0][8] = INVADER_8;

  _skin[1][0] = DAEMON;
  _skin[1][1] = DAEMON_1;
  _skin[1][2] = DAEMON_2;
  _skin[1][3] = DAEMON_3;
  _skin[1][4] = DAEMON_4;
  _skin[1][5] = DAEMON_5;
  _skin[1][6] = DAEMON_6;
  _skin[1][7] = DAEMON_7;
  _skin[1][8] = DAEMON_8;

  _skin[2][0] = YOHKO;
  _skin[2][1] = YOHKO_1;
  _skin[2][2] = YOHKO_2;
  _skin[2][3] = YOHKO_3;
  _skin[2][4] = YOHKO_4;
  _skin[2][5] = YOHKO_5;
  _skin[2][6] = YOHKO_6;
  _skin[2][7] = YOHKO_7;
  _skin[2][8] = YOHKO_8;

  _skin[3][0] = HOMICIDAL;
  _skin[3][1] = HOMICIDAL_1;
  _skin[3][2] = HOMICIDAL_2;
  _skin[3][3] = HOMICIDAL_3;
  _skin[3][4] = HOMICIDAL_4;
  _skin[3][5] = HOMICIDAL_5;
  _skin[3][6] = HOMICIDAL_6;
  _skin[3][7] = HOMICIDAL_7;
  _skin[3][8] = HOMICIDAL_8;

  _skin[4][0] = GUARDIAN;
  _skin[4][1] = GUARDIAN_1;
  _skin[4][2] = GUARDIAN_2;
  _skin[4][3] = GUARDIAN_3;
  _skin[4][4] = GUARDIAN_4;
  _skin[4][5] = GUARDIAN_5;
  _skin[4][6] = GUARDIAN_6;
  _skin[4][7] = GUARDIAN_7;
  _skin[4][8] = GUARDIAN_8;

}
