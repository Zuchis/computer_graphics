CC=gcc
CFLAGS=-c -Wall -Wextra -g -lGL -lGLU -lglut
CFLAGSL=-lpng
LDFLAGS=

SOURCES= main.cpp 
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
