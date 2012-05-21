
EXECUTABLE = box

TOPDIR = $(shell pwd)
SRCDIR = $(TOPDIR)/src
INCLUDEDIR = $(TOPDIR)/include
OBJDIR = $(TOPDIR)/obj

CC = g++
CPPFLAGS=-Wall -Werror -Wno-format
CPPFLAGS += -I$(INCLUDEDIR)
LDFLAGS = -L/usr/local/lib -lSDL -lSDL_image

OBJS = $(wildcard $(OBJDIR)/*.o)

all : src $(EXECUTABLE)

$(EXECUTABLE) : src
	$(CC) main.cpp $(CPPFLAGS) -o $@ $(OBJS) $(LDFLAGS)

src :
	make -C $(SRCDIR)

#

#
#SOURCES = $(wildcard $(SRCDIR)/*.cpp)
#OBJECTS = $(SOURCES:.cpp=.o)
#
#SRC = $(wildcard $(SRCDIR)/*.cpp)
#DEPS = $(wildcard $(INCLUDEDIR)/*.h)
#OBJS = $(wildcard $(OBJDIR)/*.o)
#
#$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
#	$(CC) -c $(CFLAGS) $<
#
#all : $(OBJS)
#
#$(OBJS) : | $(OBJDIR)
#
#$(OBJDIR) :
#	mkdir $(OBJDIR)
#
#default : src
#	g++ -Wall -Werror main.cpp src/*.cpp -I./include/ -L/usr/local/lib -lSDL -lSDL_image -o box
#
#src :
#	make -C $(SRCDIR)
#
#sample:
#
#test:
#
#mac:
#	g++ -Wall -Werror src/*.cpp -o box `sdl-config --cflags --libs` -lSDL_image
