//
// AI.h for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:02:35 2008 caner candan
// Last update Tue Jun  3 19:43:01 2008 caner candan
//

#ifndef __AI_H__
# define __AI_H__

# include <string>
# include "Socket.h"

class	AI
{
public:
  AI();
  AI(const std::string& host, int port, const std::string& team);
  AI(const AI& ai);
  ~AI();
  AI&	operator=(const AI& ai);

  void	setHost(const std::string& host, int port);
  void	setTeamName(const std::string& team);
  bool	connectToServer(void);
  bool	getHeader(void);
  bool	forkWorld(void);
private:
  void	_sendTeamName(void);
  bool	_getNbClientAndMapSize(void);

  Socket	_socket;
  std::string	_host;
  int		_port;
  std::string	_team;
  int		_x;
  int		_y;
  int		_nbClient;
};

#endif /* !__AI_H__ */
