CC=g++
CFLAGS= -Wall 
CFLAGSL=
LDFLAGS=

SOURCES= vector.cpp tester.cpp 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=exec

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(CFLAGSL)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(CFLAGSL)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)
	$(RM) *.ppm
