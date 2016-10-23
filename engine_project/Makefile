CC=g++
CFLAGS=#-g -c -Wall  -lGL -lGLU -lglut -lGLEW
CFLAGSL=#-lGL -lGLU -lglut -lGLEW
LDFLAGS=#-lGL -lGLU -lglut

#SOURCES = vector.cpp matrix.cpp matrixfactory.cpp tester_matrixf.cpp

#OBJECTS=$(SOURCES:.c=.o)

SRCDIR =src
BUILDDIR =build
TARGET =bin/runner

SRCEXT = cpp

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

EXECUTABLE= output

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(CFLAGSL)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(CFLAGSL)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)
	$(RM) *.ppm
