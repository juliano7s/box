
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <list>

#ifdef _WIN32
#include <Windows.h>
#define SLEEP Sleep(3000)
#else
#define SLEEP sleep(3)
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

using namespace Box;

typedef Vector2<int> Vector2i;
typedef Box::Rectangle<int> Rectanglei;
typedef TileBase<int> Tile;


int main(int argc, char** argv)
{
	std::cout << "Initiating main.." << std::endl;

	SDL_Surface *displaySurface = NULL;
	if ((displaySurface = SDLUtils::initSDL()) == NULL) return -1;

	ImageFactory imgFactory;

	ImageBase *img1 = imgFactory.acquire("resources/Compass.png");

	Matrix<Tile> tileMatrix(30,20);
	Vector2i tilePos(0,0);
	for (int i = 0; i < 30*20; i++)
	{
		//Tile *t = new Tile(tilePos, Vector2i(30,30));
		tilePos.x += 30;
	}

	/* SDL_CreateRGBSurfaceFrom to create a surface from void *pixelsi
	 * SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height,
     int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask); */
	SDL_Surface *created = NULL;
	created = SDL_CreateRGBSurfaceFrom(img1->pixels(), img1->width(), img1->height(),
        img1->depth(), img1->pitch(), 0xff0000, 0x00ff00, 0x0000ff, 0x00);

	SDLUtils::printSurfaceInfo(*created);
    while (true)
    {
        SDLUtils::blitSurface(displaySurface, created, 0, 0);
        SDL_Flip(displaySurface);
//        Sleep(5000);
        SLEEP;
        break;
    }

	std::vector<int> v(10);
	std::cout << "v.begin() - 1: " << *(v.begin() - 1) << "," << &(*(v.begin() - 1)) << std::endl;
	std::cout << "v.begin(): " << *v.begin() << "," << &(*v.begin()) << std::endl;
	std::cout << "v.end(): " << *v.end() << "," << &(*v.end()) << std::endl;
	std::cout << "v.end() + 1: " << *(v.end() + 1) << "," << &(*(v.end() + 1)) << std::endl;

	std::list<int> l(10);
	std::cout << "--l.begin(): " << *(--l.begin()) << "," << &(*(--l.begin())) << std::endl;
	std::cout << "l.begin(): " << *l.begin() << "," << &(*l.begin()) << std::endl;
	std::cout << "l.end(): " << *l.end() << "," << &(*l.end()) << std::endl;
	std::cout << "++l.end(): " << *(++l.end()) << "," << &(*(++l.end())) << std::endl;

    Matrix<Tile> m(5,5);
    Tile *tile1 = new Tile(Rectanglei(Vector2i(1,6), Vector2i(4,4)),
        "resources/Compass.png");
	Tile *tile2 =  new Tile(Rectanglei(Vector2i(2,4), Vector2i(3,6)),
        "resources/Compass.png");

	//Matrix<Tile>::iterator it = m.begin();
	//*(it) = *tile2;
//	const Matrix<Tile>::iterator &jt = (it++);
//	jt++;
	//(++(it++));
	//(--(it--));

    m.insertAt(*tile1, 0, 0);
	std::cout << std::endl;
	std::cout << "Tile inserted at 0,0: " << tile1 << std::endl;
    
    delete(tile1);
	delete(tile2);

	std::cout << "Indexes: " << std::endl;
	int currentLine = 0;
    for (Matrix<Tile>::iterator it = m.begin(), end = m.end(); it != end; ++it)
    {
		std::pair<int, int> elemPos = Matrix<Tile>::elementPosition(it);

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
