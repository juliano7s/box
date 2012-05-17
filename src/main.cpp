
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <Windows.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Matrix.h"
#include "Vector2.h"
#include "Rectangle.h"
#include "TileBase.h"
#include "ImageSdl.h"
#include "SDLUtils.h"

using namespace Box;

typedef Vector2<int> Vector2i;
typedef Box::Rectangle<int> Rectanglei;


int main(int argc, char** argv)
{
	std::cout << "Initiating main.." << std::endl;

	SDL_Surface *displaySurface = NULL;
	if ((displaySurface = SDLUtils::initSDL()) == NULL) return -1;

	ImageSdl img1("resources/Compass.png");
	ImageSdl img2("resources/snail.bmp");
	ImageSdl img3("resources/flash-logo.jpg");

	/* SDL_CreateRGBSurfaceFrom to create a surface from void *pixelsi
	 * SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height,
     int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask); */
	SDL_Surface *created = NULL;
	created = SDL_CreateRGBSurfaceFrom(img1.pixels(), img1.width(), img1.height(),
        img1.depth(), img1.pitch(), 0xff0000, 0x00ff00, 0x0000ff, 0x00);

	SDLUtils::printSurfaceInfo(*created);
    while (true)
    {
        SDLUtils::blitSurface(displaySurface, created, 0, 0);
        SDL_Flip(displaySurface);
        Sleep(5000);
        break;
    }

    Matrix< TileBase<int> > m(5,5);
    Matrix< TileBase<int> > n(5,5);
    TileBase<int> *tile1 = new TileBase<int>(Rectanglei(Vector2i(1,6), Vector2i(4,4)),
        "resources/Compass.png");
	TileBase<int> *tile2 =  new TileBase<int>(Rectanglei(Vector2i(2,4), Vector2i(3,6)),
        "resources/Compass.png");

	assert(m.end() != n.end());

	//Matrix< TileBase<int> >::iterator it = m.begin();
	//*(it) = *tile2;
//	const Matrix< TileBase<int> >::iterator &jt = (it++);
//	jt++;
	//(++(it++));
	//(--(it--));

    m.insertAt(*tile1, 2, 2);
	std::cout << std::endl;
	std::cout << "Tile inserted at 2,2: " << tile1 << std::endl;
    
    delete(tile1);
	delete(tile2);

    for (Matrix< TileBase<int> >::iterator it = m.begin(), end = m.end(); it != end; ++it)
    {
        std::cout << (*it).position().x << "," << (*it).position().y << " ";
    }

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << m(i,j).position().x << "," << m(i,j).position().y << " ";
		}
		std::cout << std::endl;
	}

    

    SDL_FreeSurface(created);
    SDL_FreeSurface(displaySurface);
	SDL_Quit();
	std::cout << "Terminating.." << std::endl;

    return 0;
}
