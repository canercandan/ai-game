//
// AI.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:05:25 2008 caner candan
// Last update Sat Jun  7 13:36:02 2008 caner candan
//

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <unistd.h>
#include "Socket.h"
#include "AI.h"
    
std::string	AI::actionsName[NB_ACTIONS] =
  {"avance", "droite", "gauche", "voir", "inventaire",
   "prend objet", "pose objet", "expulse",
   "broadcast", "incantation", "fork"};

std::string	AI::actionsMove[NB_ACTIONS_MOVE] =
  {"avance", "droite", "gauche"};

std::string	AI::actionsReply[NB_REPLY] =
  {"ok", "ko", "message"};

int	AI::actionsHp[NB_ACTIONS] =
  {7, 7, 7, 7, 1, 7, 7, 7, 7, 300, 42};

int	AI::nbClientPerLevel[NB_LEVEL] =
  {1, 2, 2, 4, 4, 6, 6};
int	AI::nbObjectPerLevel[NB_LEVEL][NB_OBJECT] = {
  {1, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 0, 0, 0},
  {2, 0, 1, 0, 2, 0, 0},
  {1, 1, 2, 0, 1, 0, 0},
  {1, 2, 1, 3, 0, 0, 0},
  {1, 2, 3, 0, 1, 0, 0},
  {2, 2, 2, 2, 2, 1, 0}
};

std::string	AI::objectName[NB_OBJECT] =
  {"linemate", "deraumere", "sibur", "mendiane",
   "phiras", "thystame", "nourriture"};

AI::AI()
  : _port(0), _x(0), _y(0), _level(0), _maxClient(0),
    _nbClientSameCase(0), _qtePerObject(NB_OBJECT)
{}

AI::AI(const std::string& host, int port,
       const std::string& team)
  : _host(host), _port(port), _team(team),
    _x(0), _y(0), _level(1), _maxClient(0),
    _nbClientSameCase(0), _qtePerObject(NB_OBJECT)
{}

AI::AI(const AI& ai)
{*this = ai;}

AI::~AI()
{}

AI&	AI::operator=(const AI& ai)
{
  if (this != &ai)
    {
      this->_socket = ai._socket;
      this->_host = ai._host;
      this->_port = ai._port;
      this->_team = ai._team;
      this->_x = ai._x;
      this->_y = ai._y;
      this->_level = ai._level;
      this->_maxClient = ai._maxClient;
    }
  return (*this);
}

void	AI::setHost(const std::string& host, int port)
{
  this->_host = host;
  this->_port = port;
}

void	AI::setTeamName(const std::string& team)
{
  this->_team = team;
}

bool	AI::connectToServer(void)
{
  try
    {
      this->_socket.connectSocket(this->_host, this->_port);
      if (!this->_socket.isConnected())
	throw true;
    }
  catch (bool)
    {
      std::cout << "AI: not connected" << std::endl;
      return (false);
    }
  return (true);
}

bool		AI::getHeader(void)
{
  std::string	mesg;

  try
    {
      mesg = this->_socket.recv();
      mesg =  mesg.substr(0, mesg.find_last_of('\n'));
      if (mesg != "BIENVENUE")
	throw true;
      this->_sendTeamName();
      if (!this->_getNbClientAndMapSize())
	return (false);
      if (this->_maxClient > 0)
	this->_forkWorld();
    }
  catch (bool)
    {
      std::cout << "AI: incorrect header" << std::endl;
      return (false);
    }
  return (true);
}

void	AI::_sendTeamName(void)
{
  this->_socket.send(this->_team + "\n");
}

bool			AI::_getNbClientAndMapSize(void)
{
  std::istringstream	iss;

  try
    {
      iss.str(this->_socket.recv());
      if (iss.str().substr(0, iss.str().find_last_of('\n')) == "ko")
	throw 1;
      std::cout << "AI: [" << this->_team << "] ok" << std::endl;
      iss >> this->_maxClient;
      if (this->_maxClient < 0)
	throw 2;
      iss >> this->_x;
      if (!this->_x)
	throw 3;
      iss >> this->_y;
      if (!this->_y)
	throw 4;
      std::cout << "AI: maxClient [" << this->_maxClient << "]"
		<< std::endl;
      std::cout << "AI: X: " << this->_x << "]" << std::endl;
      std::cout << "AI: Y: " << this->_y << "]" << std::endl;
    }
  catch (int e)
    {
      std::cout << "AI: ";
      if (e == 1)
	std::cout << "team not found";
      else if (e == 2)
	std::cout << "[" << this->_team << "] is full";
      else if (e == 3)
	std::cout << "x value incorrect";
      else if (e == 4)
	std::cout << "y value incorrect";
      std::cout << std::endl;
      return (false);
    }
  return (true);
}

bool	AI::_forkWorld(void)
{
  if (::fork())
    return (false);
  this->connectToServer();
  this->getHeader();
  return (true);
}

void		AI::actionLoop(void)
{
  std::string	mesg;

  ::srandom(::getpid());
  while (42)
    {
      if (!this->_isNeedFood(SEE));
      this->_seekFood();
      //::sleep(1);
//       if (!this->_hasObjectInventoryToLevelUp())
// 	{
// 	  mesg = this->_socket.sendRecv("voir\n");
// 	  if (!this->_hasObjectSeeToLevelUp(mesg))
// 	    this->_actionRandomMove();
// 	  else
// 	    this->_takeNeedObject(mesg);
// 	  continue;
// 	}
//       mesg = this->_socket.recv();
//       if (this->_hasClientSameCase(mesg))
// 	this->_moveToK(mesg);
    }
}

bool			AI::_isNeedFood(AI::Action idx)
{
  std::string		mesg;
  std::string		pattern(objectName[FOOD]);
  std::istringstream	value;
  size_t		pos;
  int			hp;

  try
    {
      mesg = this->_socket.sendRecv(actionsName[INVENTORY] + '\n');
      if ((pos = mesg.find(pattern))
	  == std::string::npos)
	throw true;
      mesg = mesg.substr(mesg.find(pattern)
			 + pattern.size());
      value.str(mesg.substr(0, mesg.find(',')));
      value >> hp;
      if (hp > actionsHp[idx])
	return (false);
    }
  catch (bool)
    {
      std::cout << "AI: food not found in inventory"
		<< std::endl;
    }
  return (true);
}

void		AI::_seekFood(void)
{
  std::string	mesg;

  while ((mesg = this->_socket.sendRecv(actionsName[SEE] + '\n'))
	 != "")
    {
      if (mesg.find(objectName[FOOD]) != std::string::npos)
	{
	  this->_goToGoodCase(mesg, FOOD);
	  this->_socket.sendRecv(actionsName[TAKE_OBJ] + ' ' +
				 objectName[FOOD] + '\n');
	  break;
	}
      this->_randomMove();
    }
}

void	AI::_goToGoodCase(const std::string& mesg,
			  AI::Object idx)
{
  int	i;
  int	size;
  int	cnt;
  int	up;
  int	begin;
  int	middle;
  int	end;
  int	add;

  cnt = 0;
  size = mesg.substr(0, mesg.find(objectName[idx])).size();
  for (i = 0; i < size; i++)
    if (mesg[i] == ',')
      cnt++;
  if (!cnt)
    return;
  up = 1;
  add = 1;
  begin = 1;
  middle = 2;
  end = 3;
  for (i = 1; i < cnt; i++)
    {
      if (i > end)
	{
	  up++;
	  add += 2;
	  begin += add;
	  middle += add + 1;
	  end += add + 2;
	}
    }
  for (i = 0; i < up; i++)
    this->_socket.sendRecv(actionsMove[UP] + '\n');
  if (cnt == middle)
    return;
  if (cnt < middle)
    {
      this->_socket.sendRecv(actionsMove[LEFT] + '\n');
      for (i = middle; i >= begin; i--)
	this->_socket.sendRecv(actionsMove[UP] + '\n');
      return;
    }
  if (cnt > middle)
    {
      this->_socket.sendRecv(actionsMove[RIGHT] + '\n');
      for (i = middle; i <= end; i++)
	this->_socket.sendRecv(actionsMove[UP] + '\n');
      return;
    }
}

void	AI::_randomMove(void)
{
  long	idx;

  idx = ::random() % NB_ACTIONS_MOVE;
  this->_socket.sendRecv(actionsMove[idx] + '\n');
  std::cout << "action [" << actionsMove[idx]
	    << "]" << std::endl;
}

bool	AI::_hasObjectInventoryToLevelUp(void)
{
  int	i;

  for (i = 0; i < NB_OBJECT; i++)
    if (nbObjectPerLevel[LEVEL(this->_level + 1)][i]
	!= _qtePerObject[i])
      return (false);
  return (true);
}

bool	AI::_hasObjectSeeToLevelUp(const std::string& mesg)
{
  int	i;

  for (i = 0; i < NB_OBJECT; i++)
    if (mesg.find(objectName[i]) == std::string::npos)
      return (false);
  return (true);
}

void	AI::_takeNeedObject(const std::string& mesg)
{
  int	i;

  for (i = 0; i < NB_OBJECT; i++)
    if (mesg.find(objectName[i]) != std::string::npos)
      if (_qtePerObject[i]
	  < nbObjectPerLevel[LEVEL(this->_level + 1)][i])
	this->_socket.sendRecv(actionsName[TAKE_OBJ] +
			       ' ' + objectName[i]);
      else if (_qtePerObject[i]
	       > nbObjectPerLevel[LEVEL(this->_level + 1)][i])
	this->_socket.sendRecv(actionsName[DROP_OBJ] +
			       ' ' + objectName[i]);
}

bool	AI::_hasClientSameCase(const std::string& mesg)
{
  if (mesg.find(MESSAGE + " 0") != std::string::npos)
    this->_nbClientSameCase++;
  return (_nbClientSameCase != 0);
}

void		AI::_moveToK(const std::string& mesg)
{
  size_t	pos;

  if ((pos = mesg.find(MESSAGE)) != std::string::npos)
    if (mesg.find(MESSAGE + " 0") == std::string::npos)
      {
	this->_nbClientSameCase = 0;
	if (mesg[pos] == '3')
	  this->_socket.sendRecv(actionsName[LEFT] + '\n');
	else if (mesg[pos] == '7')
	  this->_socket.sendRecv(actionsName[RIGHT] + '\n');
	else if (mesg[pos] == '4' ||
		 mesg[pos] == '5' ||
		 mesg[pos] == '6')
	  {
	    this->_socket.sendRecv(actionsName[RIGHT] + '\n');
	    this->_socket.sendRecv(actionsName[RIGHT] + '\n');
	  }
	this->_socket.sendRecv(actionsName[UP] + '\n');
      }
}

void	AI::_actionRandomMove(void)
{
  long	idx;

  idx = ::random() % NB_ACTIONS;
  this->_socket.sendRecv(actionsName[idx] + '\n');
  std::cout << "action [" << actionsName[idx]
	    << "]" << std::endl;
}

void	AI::_actionAI(const std::string&)
{}

bool		AI::_hasEnoughClientSameCase(void)
{
  std::string	mesg;
  int		nbclient;

  nbclient = 0;
  this->_socket.sendRecv(actionsName[BROADCAST] + '\n');
  while ((mesg = this->_socket.recv()).find(actionsReply[MESSAGE])
	 != std::string::npos)
    if (mesg.find(actionsReply[MESSAGE] + " 0") != std::string::npos)
      nbclient++;
  if (nbclient == nbClientPerLevel[LEVEL(this->_level + 1)])
    return (true);
  return (false);
}

bool		AI::_canLevelUp(void)
{
  std::string	mesg;
  int		i;

  if (this->_hasEnoughClientSameCase())
    this->_socket.send(actionsName[SEE] + '\n');
  mesg = this->_socket.recv();
  for (i = 0; i < NB_OBJECT; i++)
    if (mesg.find(objectName[i]) != std::string::npos)
      {
	break;
      }
  return (false);
}
