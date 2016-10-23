CFLAGS=#-g -c -Wall  -lGL -lGLU -lglut -lGLEW
CFLAGSL=#-lGL -lGLU -lglut -lGLEW
LDFLAGS=#-lGL -lGLU -lglut
OUT = lib/engine.a
CC= g++
ODIR = obj
SDIR = src
#INC = -Iinc

_OBJS = vector.o matrix.o matrixfactory.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	 $(CC) -c -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS) 
	 ar rvs $(OUT) $^

.PHONY: clean

clean:
	$(RM) $(ODIR)# $(EXECUTABLE)
	#$(RM) *.ppm
