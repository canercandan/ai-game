//
// AI.h for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:02:35 2008 caner candan
// Last update Thu Jun 12 14:08:26 2008 caner candan
//

#ifndef __AI_H__
# define __AI_H__

# include <string>
# include <vector>
# include "Socket.h"

# define NB_ACTIONS		11
# define NB_ACTIONS_MOVE	3
# define NB_LEVEL		7
# define NB_ROCK		6
# define NB_OBJECT		8

# define LEVEL(x)	((x) - 2)

class	AI
{
 public:
  AI();
  AI(const std::string& host, int port,
     const std::string& team);
  AI(const AI& ai);
  ~AI();
  AI&	operator=(const AI& ai);

  /*
  ** Index's infos
  */
  enum	Action
  {
    UP,
    RIGHT,
    LEFT,
    SEE,
    INVENTORY,
    TAKE_OBJ,
    DROP_OBJ,
    KICK,
    BROADCAST,
    LEVELUP,
    FORK
  };

  enum	Reply
  {
    OK,
    KO,
    MESSAGE,
    NIVEAU_CUR
  };

  enum	Protocol
    {
      IS_SAME_LEVEL,
      SAME_LEVEL
    };

  enum	Object
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    FOOD,
    PLAYER
  };

  /*
  ** Static infos
  */
  static std::string	actionsName[NB_ACTIONS];
  static std::string	actionsMove[NB_ACTIONS_MOVE];
  static int		actionsHp[NB_ACTIONS];
  static std::string	actionsReply[];

  static std::string	broadcastProtocol[];

  static int		nbClientPerLevel[NB_LEVEL];
  static int		nbObjectPerLevel[NB_LEVEL][NB_OBJECT];

  static std::string	objectName[NB_OBJECT];

  /*
  ** Main method
  */
  void	setHost(const std::string& host, int port);
  void	setTeamName(const std::string& team);
  bool	connectToServer(void);
  bool	getHeader(void);
  void	actionLoop(void);
 private:
  /*
  ** To get header
  */
  void	_sendTeamName(void);
  bool	_getNbClientAndMapSize(void);
  bool	_forkWorld(void);

  /*
  ** To get food
  */
  bool	_isNeedFood(Action idx);

  /*
  ** To level up
  */
  bool	_prepareToLevelUp(void);
  bool	_hasEnoughClientSameCase(void);
  void	_seekForPlayerToLevelUp(void);
  bool	_hasObjectInventoryToLevelUp(void);
  bool	_hasObjectSeeToLevelUp(const std::string& mesg);
  void	_emptyCase(void);
  void	_dropNeedsOnCase(void);
  void	_waitLevelUp(const std::string& mesg);
  bool	_isLockToLevelUp(const std::string& mesg);

  /*
  ** Generic method
  */
  void	_seekForObject(Object idx);
  void	_takeNeedObject(void);
  void	_moveToK(const std::string& mesg);
  void	_goToGoodCase(const std::string& mesg,
		      Object idx);
  void	_randomMove(void);

  /*
  ** Client's infos
  */
  Socket	_socket;
  std::string	_host;
  int		_port;
  std::string	_team;
  int		_x;
  int		_y;
  int		_level;
  int		_maxClient;

  std::vector<int>	_qtePerObject;
};

#endif /* !__AI_H__ */
