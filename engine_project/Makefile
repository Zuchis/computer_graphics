CFLAGS=#-g -c -Wall  -lGL -lGLU -lglut -lGLEW
CFLAGSL=#-lGL -lGLU -lglut -lGLEW
LDFLAGS=#-lGL -lGLU -lglut
OUT = lib/libengine.a
CC= g++
ODIR = obj
SDIR = src
INC = -I inc
LIB = -L lib -lengine

_OBJS = vector.o matrix.o matrixfactory.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	 $(CC) -c -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS) 
	 ar rvs $(OUT) $^

lab2:
	$(CC) test/lab2.cpp $(INC) $(LIB) -o test/bin/lab2

.PHONY: clean

clean:
	$(RM) $(ODIR)# $(EXECUTABLE)
	#$(RM) *.ppm
