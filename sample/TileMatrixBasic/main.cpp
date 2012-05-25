

#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#define SLEEP Sleep(5000)
#else
#define SLEEP sleep(5)
#endif

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Matrix.h"
#include "Vector2.h"
#include "TileBase.h"
#include "ImageFactory.h"
#include "SDLUtils.h"
#include "RendererSdl.h"

using namespace Box;

#define TILE_SIDE 40

int main(int argc, char** argv)
{
	std::cout << "Initiating main.." << std::endl;

	SDL_Surface *displaySurface = NULL;
	if ((displaySurface = SDLUtils::initSDL()) == NULL)
	{
		std::cerr << "Error initiating SDL, aborting.." << std::endl;
		return -1;
	}

	RendererSdl renderer;
	renderer.surface(displaySurface);

	ImageFactory imgFactory(renderer);
	ImageBase *img1 = imgFactory.acquire("Compass.png");

	img1->draw(Vector2i(0,0));

	Matrix<Tilei> tileMatrix(10,10);
	Vector2i tilePos(0,0);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Tilei *t = new Tilei(tilePos, Vector2i(TILE_SIDE,TILE_SIDE), img1);
			tileMatrix(i,j) = *t;
			delete t;
			tilePos.y += TILE_SIDE;
		}
		tilePos.x += TILE_SIDE;
		tilePos.y = 0;
	}

    while (true)
    {
		for (Matrix<Tilei>::iterator it = tileMatrix.begin(), end = tileMatrix.end(); it != end; ++it)
		{
//			renderer.renderTile(*it);
			img1->draw((*it).position());
		}
        SDL_Flip(displaySurface);
        SLEEP;
        break;
    }

    SDL_FreeSurface(displaySurface);
	SDL_Quit();

	std::cout << "Terminating.." << std::endl;
    return 0;
}
