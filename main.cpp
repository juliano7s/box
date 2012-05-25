
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <list>

#ifdef _WIN32
#include <Windows.h>
#define SLEEP Sleep(3000)
#else
#define SLEEP usleep(500000)
#endif

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Matrix.h"
#include "Vector2.h"
#include "Rectangle.h"
#include "TileBase.h"
#include "ImageSdl.h"
#include "ImageFactory.h"
#include "SDLUtils.h"
#include "RendererSdl.h"

using namespace Box;


int main(int argc, char** argv)
{
	std::cout << "Initiating main.." << std::endl;

	SDL_Surface *displaySurface = NULL;
	if ((displaySurface = SDLUtils::initSDL()) == NULL) return -1;

	RendererSdl renderer;
	renderer.surface(displaySurface);

	ImageFactory imgFactory;
	imgFactory.renderer(renderer);

	ImageBase *img1 = imgFactory.acquire("resources/flash-logo.jpg");

	Matrix<Tilei> tileMatrix(30,20);
	Vector2i tilePos(0,0);
	for (int i = 0; i < 30*20; i++)
	{
		//Tile *t = new Tile(tilePos, Vector2i(30,30));
		tilePos.x += 30;
		//delete t
	}

	int x = 0, y = 0;
    while (true)
    {
//		renderer.renderImage(*img1, Vector2i(++x,++y));
		img1->draw(Vector2i(x,y));
        SDL_Flip(displaySurface);
        SLEEP;
    }

	std::cout << "Indexes: " << std::endl;
	int currentLine = 0;
    for (Matrix<Tilei>::iterator it = tileMatrix.begin(), end = tileMatrix.end(); it != end; ++it)
    {
		std::pair<int, int> elemPos = Matrix<Tilei>::elementPosition(it);

		if (elemPos.first != currentLine)
		{
			std::cout << std::endl;
			currentLine = elemPos.first;
		}

		std::cout << elemPos.first << "," << elemPos.second << " ";	
    }

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Values: " << std::endl;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << tileMatrix(i,j).position().x << "," << tileMatrix(i,j).position().y << " ";
		}
		std::cout << std::endl;
	}

    SDL_FreeSurface(displaySurface);
	SDL_Quit();
	std::cout << "Terminating.." << std::endl;

    return 0;
}
