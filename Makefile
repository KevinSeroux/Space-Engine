SOURCES =	ErrorManager.cpp Vertex.cpp Triangles.cpp Mesh.cpp main.cpp
OBJECTS	=	$(SOURCES:.cpp=.o)
TARGET	=	Space-Engine
LIBS	=	$(shell sdl-config --libs) -lGL -lGLU 

all: $(OBJECTS)
	g++ $(LIBS) -o $(TARGET) $(OBJECTS)

%o: %cpp
	g++ -o $@ -c $<

x: all
	./$(TARGET)

clean:
	rm -rf $(OBJECTS)

superclean : clean
	rm -rf $(TARGET)

