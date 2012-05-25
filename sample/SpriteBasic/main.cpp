

#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#define SLEEP Sleep(5000)
#else
#define SLEEP sleep(5)
#endif

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Sprite.h"
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
	ImageBase *img1 = imgFactory.acquire("star-green.png");

	Sprite starSprite(*img1, "star-data-sheet.spr");

    while (true)
    {
        SDL_Flip(displaySurface);
		usleep(100000);
		break;
    }

    SDL_FreeSurface(displaySurface);
	SDL_Quit();

	std::cout << "Terminating.." << std::endl;
    return 0;
}
