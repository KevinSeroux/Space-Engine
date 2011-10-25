CPP=		g++
CXXFLAGS=	-W -Wall -ansi -pedantic
LDFLAGS=	$(shell sdl-config --libs) -lGL -lGLU
EXEC=		Space-Engine
SRC=		$(wildcard *.cpp)
OBJ=		$(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CPP) $(LDFLAGS) -o $(EXEC) $(OBJ)

main.o:
%.o: %.cpp
	$(CPP) -o $@ -c $<

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
