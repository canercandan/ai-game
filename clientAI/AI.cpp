//
// AI.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:05:25 2008 caner candan
// Last update Mon Jun  2 13:14:48 2008 caner candan
//

#include <string>
//#include "Socket.h"
#include "AI.h"

AI::AI(const std::string& host, int port)
  : _host(host), _port(port), _socket(host, port)
{}

AI::AI(const AI& ai)
{*this = ai;}

AI::~AI()
{}

AI&	AI::operator=(const AI& ai)
{
  if (*this != ai)
    {
      this->_host = ai._host;
      this->_port = ai._port;
      this->_socket = ai._socket;
    }
  return (*this):
}

