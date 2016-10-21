CC=g++
CFLAGS=#-g -c -Wall  -lGL -lGLU -lglut -lGLEW
CFLAGSL=#-lGL -lGLU -lglut -lGLEW
LDFLAGS=#-lGL -lGLU -lglut

#SRCEXT = cpp

SOURCES = vector.cpp matrix.cpp matrixfactory.cpp tester_matrixf.cpp

#SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

OBJECTS=$(SOURCES:.c=.o)

#OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

EXECUTABLE= output

all: $(SOURCES) $(EXECUTABLE)

#all: g++ src/vector.cpp src/matrix.cpp src/matrixfactory.cpp test/tester_matrif.cpp -o test/test-factory

#test-factory: $(CC) $(SOURCES) test/tester_matrixf.cpp -o test/tester-factory

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(CFLAGSL)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(CFLAGSL)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)
	$(RM) *.ppm
