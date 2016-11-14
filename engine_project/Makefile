CFLAGS= -lGL -lGLU -lglut -lGLEW
CFLAGSL=#-lGL -lGLU -lglut -lGLEW
LDFLAGS=#-lGL -lGLU -lglut

OUT = lib/libengine.a

CC= g++

ODIR = obj
SDIR = src

INC = -I inc
LIB = -L lib -lengine

TAN = app/drawing-application/tangram.cpp
TANTARGET = build/tangram

_OBJS = vector.o matrix.o matrixfactory.o objects.o shaderprogram.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	 $(CC) -c -o $@ $<

$(OUT): $(OBJS) 
	 ar rvs $(OUT) $^

lab2:
	$(CC) test/lab2.cpp $(INC) $(LIB) -o test/bin/lab2

tangram:
	$(TAN) $(TANTARGET)

$(TANTARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(CFLAGSL)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(CFLAGSL)

.PHONY: clean

clean:
	$(RM) $(ODIR)# $(EXECUTABLE)
