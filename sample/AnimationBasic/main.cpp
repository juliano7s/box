

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
	ImageBase *img1 = imgFactory.acquire("star-green.png");
	Animation starAnimation("spinning", Vector2<int>(0,0), img1, Vector2<int>(80,80), 71);
	starAnimation.timesToShowFrame(1);

	Animation starAnimation2("spinning", Vector2<int>(90,0), img1, Vector2<int>(80,80), 71);
	starAnimation2.timesToShowFrame(2);

	Animation starAnimation3("spinning", Vector2<int>(180,0), img1, Vector2<int>(80,80), 71);
	starAnimation3.timesToShowFrame(5);

	ImageBase *yoshiSheet = imgFactory.acquire("yoshi.bmp");
	Animation yoshiAnimation("walking", Vector2<int>(90,0), yoshiSheet, Vector2<int>(64,64), 8);

	ImageBase *braidSheet = imgFactory.acquire("dude_animation_sheet.png");
	Animation braidAnimation("running", Vector2<int>(90,90), braidSheet, Vector2<int>(138,148), 27);

    while (true)
    {
		starAnimation.animate();
		starAnimation2.animate();
		starAnimation3.animate();
//		yoshiAnimation.animate();
//		braidAnimation.animate();
        SDL_Flip(displaySurface);
		usleep(10);
    }

    SDL_FreeSurface(displaySurface);
	SDL_Quit();

	std::cout << "Terminating.." << std::endl;
    return 0;
}
