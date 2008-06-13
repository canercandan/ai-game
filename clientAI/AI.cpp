//
// AI.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:05:25 2008 caner candan
// Last update Fri Jun 13 15:31:52 2008 caner candan
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

std::string	AI::protocolMesg[] =
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
  : _port(0), _x(0), _y(0), _level(0),
    _maxClient(0), _qtePerObject(NB_OBJECT)
{}

AI::AI(const std::string& host, int port,
       const std::string& team)
  : _host(host), _port(port), _team(team),
    _x(0), _y(0), _level(0), _maxClient(0),
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
      mesg =  mesg.substr(0, mesg.find_last_of(END));
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
  this->_socket.send(this->_team + END);
}

bool			AI::_getNbClientAndMapSize(void)
{
  std::istringstream	iss;

  try
    {
      iss.str(this->_socket.recv());
      if (iss.str().substr(0, iss.str().find_last_of(END))
	  == actionsReply[KO])
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
      this->_socket.send(actionsName[SEE] + END);
      while ((mesg = this->_socket.recv()) != EMPTY)
	{
	  if (!this->_level)
	    this->_foundLevel(mesg);
// 	  if (this->_isNeedFood(SEE))
// 	    this->_seekForObject(FOOD);
	  if (this->_prepareToLevelUp())
	    if (this->_isLockToLevelUp(mesg))
	      this->_waitLevelUp(mesg);
	    else
	      {
		this->_seekForPlayerToLevelUp();
		this->_emptyCase();
		this->_dropNeedsOnCase();
		this->_socket.sendRecv(actionsName[LEVELUP] + END);
		if (this->_socket.recv()
		    == actionsReply[CUR_LEVEL])
		  this->_level++;
	      }
	  this->_socket.send(actionsName[SEE] + END);
	}
      throw true;
    }
  catch (bool)
    {
      std::cout << "AI: trame incorrect to loop "
		<< "action" << std::endl;
    }
}

void		AI::_foundLevel(const std::string& mesg)
{
  size_t	size;
  size_t	i;
  size_t	cnt;
  size_t	add;

  size = mesg.size();
  cnt = 0;
  for (i = 0; i < size; i++)
    if (mesg[i] == CM)
      cnt++;
  add = 1;
  for (i = 0; i < cnt; i += add)
    {
      this->_level++;
      add += 2;
    }
}

bool			AI::_isLockToLevelUp(const std::string& mesg)
{
  std::stringstream	is_same_level;
  std::stringstream	same_level;

  try
    {
      if (this->_level <= 1)
	return (false);
      is_same_level << protocolMesg[IS_SAME_LEVEL]
		    << SP << this->_level;
      if (mesg.find(is_same_level.str())
	  != std::string::npos)
	{
	  same_level << actionsName[BROADCAST] << SP
		     << protocolMesg[SAME_LEVEL] << SP
		     << this->_level << END;
	  if (this->_socket.sendRecv(same_level.str(), true)
	      == EMPTY)
	    throw true;
	  return (true);
	}
      if (this->_socket.sendRecv(is_same_level.str(), true)
	  == EMPTY)
	throw true;
    }
  catch (bool)
    {
      std::cout << "AI: trame incorrect to lock to "
		<< "level up" << std::endl;
    }
  return (false);
}

void		AI::_waitLevelUp(const std::string& mesg)
{
  std::string	recv;

  try
    {
      if ((recv = mesg) == EMPTY)
	throw true;
      while (42)
	{
	  std::cout << "I WaiT MAN" << std::endl;
	  if ((recv = this->_socket.recv())
	      == EMPTY)
	    throw true;
	  if (recv.find(actionsReply[CUR_LEVEL])
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
      this->_socket.sendRecv(actionsName[DROP_OBJ] + SP
			     + objectName[i] + END);
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
      if ((mesg = this->_socket.sendRecv(actionsName[SEE] + END))
	  == EMPTY)
	return;
      mesg = mesg.substr(0, mesg.find(CM));
      for (i = 0; i < NB_ROCK + 1; i++)
	{
	  if (mesg.find(objectName[i]) == std::string::npos)
	    continue;
	  this->_socket.sendRecv(actionsName[TAKE_OBJ] + SP
				 + objectName[i] + END);
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
      if ((mesg = this->_socket.sendRecv(actionsName[INVENTORY] + END))
	  == EMPTY)
	throw true;
      for (i = 0; i < NB_ROCK; i++)
	{
	  if ((pos = mesg.find(objectName[i])) == std::string::npos)
	    return (false);
	  mesg = mesg.substr(pos + objectName[i].size() + 1);
	  iss.str(mesg.substr(0, mesg.find(SP)));
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
      mesg = this->_socket.sendRecv(actionsName[INVENTORY] + END);
      if ((pos = mesg.find(objectName[FOOD]))
	  == std::string::npos)
	throw true;
      mesg = mesg.substr(mesg.find(objectName[FOOD])
			 + objectName[FOOD].size());
      value.str(mesg.substr(0, mesg.find(CM)));
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
	  if ((mesg = this->_socket.sendRecv(actionsName[SEE] + END))
	      == EMPTY)
	    throw true;
	  if (mesg.find(objectName[idx]) != std::string::npos)
	    {
	      this->_goToGoodCase(mesg, idx);
	      if (this->_socket.sendRecv(actionsName[TAKE_OBJ] + SP +
					 objectName[idx] + END)
		  == actionsReply[OK] + END)
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
	  if ((mesg = this->_socket.sendRecv(actionsName[SEE] + END))
	      == EMPTY)
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
    if (mesg[i] == CM)
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
    this->_socket.sendRecv(actionsMove[UP] + END);
  if (cnt == middle)
    return;
  if (cnt < middle)
    {
      this->_socket.sendRecv(actionsMove[LEFT] + END);
      for (i = middle; i >= begin; i--)
	this->_socket.sendRecv(actionsMove[UP] + END);
      return;
    }
  if (cnt > middle)
    {
      this->_socket.sendRecv(actionsMove[RIGHT] + END);
      for (i = middle; i <= end; i++)
	this->_socket.sendRecv(actionsMove[UP] + END);
      return;
    }
}

void	AI::_randomMove(void)
{
  long	idx;

  idx = ::random() % NB_ACTIONS_MOVE;
  this->_socket.sendRecv(actionsMove[idx] + END);
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
      if ((mesg = this->_socket.sendRecv(actionsName[SEE] + END))
	  == EMPTY)
	throw true;
      for (i = 0; i < NB_OBJECT; i++)
	if (mesg.find(objectName[i]) != std::string::npos)
	  if (_qtePerObject[i]
	      < nbObjectPerLevel[LEVEL(this->_level + 1)][i])
	    this->_socket.sendRecv(actionsName[TAKE_OBJ] +
				   SP + objectName[i]);
	  else if (_qtePerObject[i]
		   > nbObjectPerLevel[LEVEL(this->_level + 1)][i])
	    this->_socket.sendRecv(actionsName[DROP_OBJ] +
				   SP + objectName[i]);
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
      if (mesg == EMPTY)
	throw 1;
      if (mesg.find(actionsReply[MESSAGE] + " 0") != std::string::npos)
	throw 2;
      if ((pos = mesg.find(actionsReply[MESSAGE])) != std::string::npos)
	{
	  pos += actionsReply[MESSAGE].size() + 1;
	  if (mesg[pos] == '3')
	    this->_socket.sendRecv(actionsName[LEFT] + END);
	  else if (mesg[pos] == '7')
	    this->_socket.sendRecv(actionsName[RIGHT] + END);
	  else if (mesg[pos] == '4' ||
		   mesg[pos] == '5' ||
		   mesg[pos] == '6')
	    {
	      this->_socket.sendRecv(actionsName[RIGHT] + END);
	      this->_socket.sendRecv(actionsName[RIGHT] + END);
	    }
	  i = 0;
	  while ((recv = this->_socket.sendRecv(actionsName[SEE] + END))
		 != EMPTY)
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
		    this->_socket.sendRecv(actionsName[RIGHT] + END);
		  else
		    this->_socket.sendRecv(actionsName[LEFT] + END);
		  this->_socket.sendRecv(actionsName[UP] + END);
		}
	      else if (mesg[pos] == '6' || mesg[pos] == '2')
		{
		  if (!(i % 2))
		    this->_socket.sendRecv(actionsName[LEFT] + END);
		  else
		    this->_socket.sendRecv(actionsName[RIGHT] + END);
		  this->_socket.sendRecv(actionsName[UP] + END);
		}
	      else
		this->_socket.sendRecv(actionsName[UP] + END);
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
      if ((mesg = this->_socket.sendRecv(actionsName[SEE] + END))
	  == EMPTY)
	throw true;
      mesg = mesg.substr(0, mesg.find(CM));
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
