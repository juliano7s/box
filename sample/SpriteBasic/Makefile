include ../../default.mk

EXECUTABLE = SpriteBasic 

CC = g++
CFLAGS = -I../../include/
OBJECTS = ../../obj/*.o

$(EXECUTABLE) : $(OBJECTS) main.cpp
	$(CC) main.cpp -o $(EXECUTABLE) $(CFLAGS) $(OBJECTS) $(LDFLAGS)

clean :
	rm $(EXECUTABLE)
