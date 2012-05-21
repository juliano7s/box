
UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
LDFLAGS := -L/usr/local/lib -lSDL -lSDL_image
endif
ifeq ($(UNAME), Darwin)
LDFLAGS := `sdl-config --cflags --libs` -lSDL_image
endif

