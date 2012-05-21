ALL_C=$(shell find . -name "*.cpp")
SOURCES?=$(ALL_C)
OBJECTS?=$(SOURCES:.cpp=.o)

SRCDIR = ../src
INCLUDEDIR = ../include
OBJDIR = ../obj

CC = g++
CPPFLAGS=-Wall -Werror -Wno-format
CPPFLAGS += -I$(INCLUDEDIR)

LDFLAGS = -L/usr/local/lib -lSDL -lSDL_image

all : $(OBJDIR)
	$(CC) -c $(SOURCES) $(CPPFLAGS)
	mv *.o $(OBJDIR)

$(OBJDIR) :
	mkdir $(OBJDIR)

