//
// AI.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:05:25 2008 caner candan
// Last update Thu Jun 12 14:10:04 2008 caner candan
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
   "prend", "pose", "expulse", "broadcast",
   "incantation", "fork"};

std::string	AI::actionsMove[NB_ACTIONS_MOVE] =
  {"avance", "droite", "gauche"};

std::string	AI::actionsReply[] =
  {"ok", "ko", "message", "niveau actuel"};

std::string	AI::broadcastProtocol[] =
  {"level ?", "level ok"};

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
   "phiras", "thystame", "nourriture", "joueur"};

AI::AI()
  : _port(0), _x(0), _y(0), _level(1),
    _maxClient(0), _qtePerObject(NB_OBJECT)
{}

AI::AI(const std::string& host, int port,
       const std::string& team)
  : _host(host), _port(port), _team(team),
    _x(0), _y(0), _level(1), _maxClient(0),
    _qtePerObject(NB_OBJECT)
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
      iss >> this->_x;
      iss >> this->_y;
      if (this->_maxClient < 0)
	throw 2;
      if (!this->_x)
	{
	  iss.str(this->_socket.recv());
	  iss >> this->_x;
	  iss >> this->_y;
	}
      if (!this->_x)
	throw 3;
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
  try
    {
  while (42)
    {
      if ((mesg = this->_socket.recv()) == "")
	throw true;
      if (this->_isNeedFood(SEE))
	this->_seekForObject(FOOD);
      if (this->_isLockToLevelUp(mesg))
	this->_waitLevelUp();
      if (this->_prepareToLevelUp())
	{
	  this->_seekForPlayerToLevelUp();
	  this->_emptyCase();
	  this->_dropNeedsOnCase();
	  this->_socket.sendRecv(actionsName[LEVELUP] + '\n');
	  this->_socket.recv(true);
	  break;
	}
    }
    }
  catch (bool)
    {
      std::cout << "AI: trame incorrect to loop "
		<< "action" << std::endl;
    }
}

bool	AI::_isLockToLevelUp(const std::string& mesg)
{
  try
    {
      if ((mesg = this->_socket.sendRecv(actionsName[BROADCAST]
					 + IS_SAME_LEVEL + ' '
					 + this->_level + '\n'))
	  == "")
	throw true;

    }
  catch (bool)
    {
      std::cout << "AI: trame incorrect to lock to "
		<< "level up" << std::endl;
    }
}

void		AI::_waitLevelUp(const std::string& mesg)
{
  std::string	recv;

  try
    {
      if ((recv = mesg) == "")
	throw true;
      while (42)
	{
	  if ((recv = this->_socket.recv())
	      == "")
	    throw true;
	  if (recv.find(actionsReply[NIVEAU_CUR])
	      != std::string::npos)
	    break;
	}
    }
  catch (bool)
    {
      std::cout << "AI: trame incorrect to wait "
		<< "level up" << std::endl;
    }
}

void	AI::_dropNeedsOnCase(void)
{
  int	i;
  int	j;

  for (i = 0; i < NB_ROCK; i++)
    for (j = 0; j < nbObjectPerLevel[LEVEL(this->_level + 1)][i]; j++)
      this->_socket.sendRecv(actionsName[DROP_OBJ] + ' '
			     + objectName[i] + '\n', true);
}

void		AI::_emptyCase(void)
{
  std::string	mesg;
  int		fnd;
  int		i;

  fnd = 1;
  while (fnd)
    {
      fnd = 0;
      if ((mesg = this->_socket.sendRecv(actionsName[SEE] + '\n')) == "")
	return;
      mesg = mesg.substr(0, mesg.find(','));
      for (i = 0; i < NB_ROCK + 1; i++)
	{
	  if (mesg.find(objectName[i]) == std::string::npos)
	    continue;
	  this->_socket.sendRecv(actionsName[TAKE_OBJ] + ' '
				 + objectName[i] + '\n');
	  fnd = 1;
	}
    }
}

bool			AI::_prepareToLevelUp(void)
{
  std::istringstream	iss;
  std::string		mesg;
  size_t		pos;
  int			value;
  int			i;

  try
    {
      if ((mesg = this->_socket.sendRecv(actionsName[INVENTORY] + '\n')) == "")
	throw true;
      for (i = 0; i < NB_ROCK; i++)
	{
	  if ((pos = mesg.find(objectName[i])) == std::string::npos)
	    return (false);
	  mesg = mesg.substr(pos + objectName[i].size() + 1);
	  iss.str(mesg.substr(0, mesg.find(' ')));
	  iss >> value;
	  if (nbObjectPerLevel[LEVEL(this->_level + 1)][i] > value)
	    this->_seekForObject(static_cast<Object>(i));
	}
      return (true);
    }
  catch (bool)
    {
      std::cout << "AI: trame incorrect to prepare "
		<< "to level up" << std::endl;
    }
  return (false);
}

bool			AI::_isNeedFood(AI::Action idx)
{
  std::string		mesg;
  std::istringstream	value;
  size_t		pos;
  int			hp;

  try
    {
      mesg = this->_socket.sendRecv(actionsName[INVENTORY] + '\n');
      if ((pos = mesg.find(objectName[FOOD]))
	  == std::string::npos)
	throw true;
      mesg = mesg.substr(mesg.find(objectName[FOOD])
			 + objectName[FOOD].size());
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

void		AI::_seekForObject(AI::Object idx)
{
  std::string	mesg;

  try
    {
      while (42)
	{
	  if ((mesg = this->_socket.sendRecv(actionsName[SEE] + '\n')) == "")
	    throw true;
	  if (mesg.find(objectName[idx]) != std::string::npos)
	    {
	      this->_goToGoodCase(mesg, idx);
	      if (this->_socket.sendRecv(actionsName[TAKE_OBJ] + ' ' +
					 objectName[idx] + '\n', true)
		  == actionsReply[OK] + '\n')
		break;
	    }
	  this->_randomMove();
	}
    }
  catch (bool)
    {
      std::cout << "trame incorrect to seek for object"
		<< std::endl;
    }
}

void		AI::_seekForPlayerToLevelUp(void)
{
  std::string	mesg;

  try
    {
      if (nbClientPerLevel[LEVEL(this->_level + 1)] <= 1)
	throw 1;
      while (42)
	{
	  if ((mesg = this->_socket.sendRecv(actionsName[SEE] + '\n')) == "")
	    throw 2;
	  mesg = mesg.substr(objectName[PLAYER].size());
	  if (mesg.find(objectName[PLAYER]) != std::string::npos)
	    {
	      this->_goToGoodCase(mesg, PLAYER);
	      if (this->_hasEnoughClientSameCase())
		throw 3;
	    }
	  this->_randomMove();
	}
    }
  catch (int e)
    {
      std::cout << "AI: ";
      if (e == 1)
	std::cout << "player not necessary";
      else if (e == 2)
	std::cout << "trame incorrect to seek for "
		  << "player to level up";
      else if (e == 3)
	std::cout << "player found";
      std::cout << std::endl;
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
    if (i > end)
      {
	up++;
	add += 2;
	begin += add;
	middle += add + 1;
	end += add + 2;
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

void		AI::_takeNeedObject(void)
{
  std::string	mesg;
  int		i;

  try
    {
      if ((mesg = this->_socket.sendRecv(actionsName[SEE] + '\n')) == "")
	throw true;
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
  catch (bool)
    {
      std::cout << "trame incorrect to take need object"
		<< std::endl;
    }
}

void		AI::_moveToK(const std::string& mesg)
{
  std::string	recv;
  size_t	pos;
  int		i;

  try
    {
      if (mesg == "")
	throw 1;
      if (mesg.find(actionsReply[MESSAGE] + " 0") != std::string::npos)
	throw 2;
      if ((pos = mesg.find(actionsReply[MESSAGE])) != std::string::npos)
	{
	  pos += actionsReply[MESSAGE].size() + 1;
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
	  i = 0;
	  while ((recv = this->_socket.sendRecv(actionsName[SEE] + '\n'))
		 != "")
	    {
	      if (recv.substr(objectName[PLAYER].size()
			      ).find(objectName[PLAYER])
		  != std::string::npos)
		{
		  this->_goToGoodCase(recv.substr(objectName[PLAYER].size()), PLAYER);
		  break;
		}
	      if (mesg[pos] == '4' || mesg[pos] == '8')
		{
		  if (!(i % 2))
		    this->_socket.sendRecv(actionsName[RIGHT] + '\n');
		  else
		    this->_socket.sendRecv(actionsName[LEFT] + '\n');
		  this->_socket.sendRecv(actionsName[UP] + '\n');
		}
	      else if (mesg[pos] == '6' || mesg[pos] == '2')
		{
		  if (!(i % 2))
		    this->_socket.sendRecv(actionsName[LEFT] + '\n');
		  else
		    this->_socket.sendRecv(actionsName[RIGHT] + '\n');
		  this->_socket.sendRecv(actionsName[UP] + '\n');
		}
	      else
		this->_socket.sendRecv(actionsName[UP] + '\n');
	      i++;
	    }
	}
    }
  catch (int e)
    {
      std::cout << "AI: ";
      if (e == 1)
	std::cout << "trame incorrect to going to good case";
      else if (e == 2)
	std::cout << "it's the same case that client one";
      std::cout << std::endl;
    }
}

bool		AI::_hasEnoughClientSameCase(void)
{
  std::string	mesg;
  int		cnt;
  size_t	pos;

  try
    {
      if ((mesg = this->_socket.sendRecv(actionsName[SEE] + '\n')) == "")
	throw true;
      mesg = mesg.substr(0, mesg.find(','));
      cnt = 0;
      while ((pos = mesg.find(objectName[PLAYER])) != std::string::npos)
	{
	  cnt++;
	  mesg = mesg.substr(pos + objectName[PLAYER].size());
	}
      if (cnt == nbClientPerLevel[LEVEL(this->_level + 1)])
	return (true);
    }
  catch (bool)
    {
      std::cout << "AI: trame incorrect to test if there"
		<< "are enought client in the same case"
		<< std::endl;
    }
  return (false);
}
