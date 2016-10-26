CC=g++
CFLAGS=-c -Wall -g -lGL -lGLU -lglut -lGLEW #-lsfml-window -lsfml-system
CFLAGSL=-lGL -lGLU -lglut -lGLEW #-lsfml-window -lsfml-system
LDFLAGS=#-lGL -lGLU -lglut

SOURCES= tangram.cpp GLSLProgram.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=magic

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(CFLAGSL)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(CFLAGSL)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)
	$(RM) *.ppm
