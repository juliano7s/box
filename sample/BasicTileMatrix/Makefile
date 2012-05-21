
EXECUTABLE = BasicTileMatrix

CC = g++
CFLAGS = -I../../include/
LDFLAGS = -lSDL -lSDL_image
OBJECTS = ../../obj/*.o

$(EXECUTABLE) :
	$(CC) *.cpp -o $(EXECUTABLE) $(CFLAGS) $(OBJECTS) $(LDFLAGS)

clean :
	rm $(EXECUTABLE)
