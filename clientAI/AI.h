//
// AI.h for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:02:35 2008 caner candan
// Last update Wed Jun  4 09:30:37 2008 caner candan
//

#ifndef __AI_H__
# define __AI_H__

# include <string>
# include "Socket.h"

# define NB_ACTIONS	10

class	AI
{
public:
  AI();
  AI(const std::string& host, int port, const std::string& team);
  AI(const AI& ai);
  ~AI();
  AI&	operator=(const AI& ai);

  static std::string	actions[];

  void	setHost(const std::string& host, int port);
  void	setTeamName(const std::string& team);
  bool	connectToServer(void);
  bool	getHeader(void);
  void	actionLoop(void);
private:
  void	_sendTeamName(void);
  bool	_getNbClientAndMapSize(void);
  bool	_forkWorld(void);
  void	_actionRandom(void);
  void	_actionAI(const std::string& mesg);

  Socket	_socket;
  std::string	_host;
  int		_port;
  std::string	_team;
  int		_x;
  int		_y;
  int		_nbClient;
};

#endif /* !__AI_H__ */
