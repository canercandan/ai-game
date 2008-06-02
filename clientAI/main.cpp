//
// main.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 11:20:25 2008 caner candan
// Last update Mon Jun  2 13:02:22 2008 caner candan
//

#include <iostream>
#include "Socket.h"
#include "AI.h"

int	main(void)
{
  Socket	sck("localhost", 1234);

  sck.send("coucou tout le monde\n");
  std::cout << "recv: " << std::endl << sck.recv();
  std::cout << std::boolalpha << sck.isConnected() << std::endl;
  return (0);
}
