##
## Makefile for Obs3D in /home/hochwe_f/zappy/observator_3d
## 
## Made by florent hochwelker
## Login   <hochwe_f@epitech.net>
## 
## Started on  Fri Jun  6 18:48:55 2008 florent hochwelker
## Last update Fri Jun  6 19:59:46 2008 florent hochwelker
##

CC		=	g++
SRC		=	main.cpp \
			Obs.cpp \
			Socket.cpp \
			Window.cpp \
			Player.cpp

OBJ		=	$(SRC:.cpp=.o)
NAME		=	obs_3d
INCLUDES	=	-I. -I/usr/local/include/irrlicht/ -I/usr/X11R6/include -I../include
LIB		=	-L/usr/X11R6/lib -L/usr/local/lib 		\
			-lGL -lGLU -lXxf86vm -lXext -lX11 -lpng -ljpeg	\
			-lIrrlicht
CXXFLAGS	=	-O3 -ffast-math -W -Wall $(INCLUDES)


all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f *~
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
