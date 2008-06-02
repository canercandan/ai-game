//
// AI.h for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:02:35 2008 caner candan
// Last update Mon Jun  2 13:14:04 2008 caner candan
//

#ifndef __AI_H__
# define __AI_H__

# include <string>
# include "Socket.h"

class	AI
{
public:
  AI(const std::string& host, int port);
  AI(const AI& ai);
  ~AI();
  AI&	operator=(const AI& ai);

private:
  const std::string&	_host;
  int			_port;
  const Socket&		_socket;
};

#endif /* !__AI_H__ */
