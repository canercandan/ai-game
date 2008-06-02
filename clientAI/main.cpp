//
// main.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 11:20:25 2008 caner candan
// Last update Tue Jun  3 00:43:04 2008 caner candan
//

#include <iostream>
#include "Socket.h"
#include "AI.h"

int		main(void)
{
  AI		ai("localhost", 1234, "team");

  ai.connectToServer();
  ai.getHeader();
  return (0);
}
