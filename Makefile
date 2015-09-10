CC = g++
FLAGS =-lGLU -lGL -lglut

all:
	$(CC) blackScreen.cpp -o blackScreen $(FLAGS)	
	
snowman:
	$(CC) snowman.cpp -o snowman $(FLAGS)	

clean:
	rm -f *.o core

