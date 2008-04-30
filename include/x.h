/*
** x.h for x in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 15 15:42:08 2008 caner candan
** Last update Wed Apr 30 16:29:51 2008 caner candan
*/

#ifndef __X_H__
# define __X_H__

/*
** Exits, debug and errors:
*/
# define EXIT_SUCC	00
# define EXIT_FAIL	42

/*
** Return's values
*/
# define FALSE		-1
# define TRUE		00
# define WAIT		01
# define ERROR		02
# define QUIT		03
# define EMPTY		04
# define DENIED		05

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
