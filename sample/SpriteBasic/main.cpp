

#include <iostream>

#include <math.h>

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
#define PI 3.14159265


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

	int x = 0, y = 0;
	int mx = 50, direction = 1;
	int radius = 70;
	float angle = 0;
    while (true)
    {
		/* Clears the screen */
//		SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0,0,0));
		SDL_FillRect(displaySurface, NULL, SDL_MapRGB(displaySurface->format, 0,0,0));

		x = mx + cos(angle * PI/180) * radius;
		y = 150 + sin(angle * PI/180) * radius;

		starSprite.move(Vector2<int>(x,y));
		starSprite.show();

        SDL_Flip(displaySurface);
		usleep(20000);

		angle = (angle < 360) ? angle + 10 : angle = 0;

		if (mx <= 50)
			direction = 1;

		if (mx >= 450)
			direction = -1;

		mx += direction * 3;
    }

    SDL_FreeSurface(displaySurface);
	SDL_Quit();

	std::cout << "Terminating.." << std::endl;
    return 0;
}
