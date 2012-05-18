

default:
	g++ -Wall -Werror src/*.cpp -L/usr/local/lib -lSDL -lSDL_image -o box

mac:
	g++ -Wall -Werror src/*.cpp -o box `sdl-config --cflags --libs` -lSDL_image
