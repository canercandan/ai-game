/*
** x.h for x in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 15 15:42:08 2008 caner candan
** Last update Wed Apr 30 17:13:50 2008 florent hochwelker
*/

#ifndef __X_H__
# define __X_H__

/*
** Exits, debug and errors:
*/
# define EXIT_SUCC	0
# define EXIT_FAIL	42

/*
** Return's values
*/
# define FALSE		-1
# define TRUE		0
# define WAIT		1
# define ERROR		2
# define QUIT		3
# define EMPTY		4
# define DENIED		5

/*
** Socket control:
*/
int	xaccept(int s, void *addr, void *addrlen);
int	xbind(int s, const void *addr, void *addrlen);
int	xconnect(int s, const void *name, void *namelen);
int	xlisten(int s, int backlog);
int	xrecv(int s, void *buf, int len, int flags);
int	xsend(int s, const void *msg, int len, int flags);
int	xsocket(int domain, int type, int protocol);
int	xfork(void);

/*
** My/x library:
*/
void	*xmalloc(int size);

/*
** File's functions:
*/
int	xopen(char *path, int flags);
int	xclose(int fd);

#endif /* !__X_H__ */
