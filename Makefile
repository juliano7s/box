
UNAME = $(shell uname)
EXECUTABLE = box

TOPDIR = $(shell pwd)
SRCDIR = $(TOPDIR)/src
INCLUDEDIR = $(TOPDIR)/include
OBJDIR = $(TOPDIR)/obj
SAMPLEDIR = $(TOPDIR)/sample

CC = g++
CPPFLAGS=-Wall -Werror -Wno-format
CPPFLAGS += -I$(INCLUDEDIR)

ifeq ($(UNAME), Linux)
LDFLAGS = -L/usr/local/lib -lSDL -lSDL_image
endif
ifeq ($(UNAME), Darwin)
LDFLAGS = `sdl-config --cflags --libs` -lSDL_image
endif

OBJS = $(wildcard $(OBJDIR)/*.o)

all : $(EXECUTABLE)

$(EXECUTABLE) : source samples
	$(CC) main.cpp $(CPPFLAGS) -o $@ $(OBJS) $(LDFLAGS)

source :
	make -C $(SRCDIR)

samples :
	make -C $(SAMPLEDIR)

clean :
	rm -r $(OBJDIR)
	rm $(TOPDIR)/$(EXECUTABLE)
	make -C $(SAMPLEDIR) clean
