include ../../default.mk

EXECUTABLE = BasicAnimation

CC = g++
CFLAGS = -I../../include/
OBJECTS = ../../obj/*.o

$(EXECUTABLE) :
	$(CC) *.cpp -o $(EXECUTABLE) $(CFLAGS) $(OBJECTS) $(LDFLAGS)

clean :
	rm $(EXECUTABLE)
