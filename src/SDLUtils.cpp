
#include "SDLUtils.h"

#include <iostream>

namespace Box
{
	namespace SDLUtils
	{

Uint32 getPixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

SDL_Surface* initSDL()
{
	SDL_Surface *surface = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return NULL;

//	if ((surface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_OPENGL)) == 0)
//		return NULL;

	if ((surface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == 0)
		return NULL;

	SDL_WM_SetCaption("Box Game Engine", 0);

	/* OpenGL options */
//	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return surface;
}

void printSurfaceInfo(const SDL_Surface &surface)
{
	std::cout << std::endl;
	std::cout << " pitch = " << surface.pitch << std::endl;
	std::cout << " bpp = " << (int) surface.format->BytesPerPixel << std::endl;
	std::cout << " w x h = " << (int) surface.w << " x " << surface.h << std::endl;
	std::cout << " RGBAmask = " << std::hex << surface.format->Rmask << " " <<
		surface.format->Gmask << " " << surface.format->Bmask << " " <<
		surface.format->Amask << std::endl;
	std::cout << std::dec;
}

SDL_Surface* loadImage(const char *file)
{
	SDL_Surface *surfTemp = NULL;
	SDL_Surface *surfReturn = NULL;

	surfTemp = IMG_Load(file);
	if (!surfTemp)
	{
		return NULL;
	}

	surfReturn = SDL_DisplayFormat(surfTemp);

	SDL_FreeSurface(surfTemp);

	printSurfaceInfo(*surfTemp);

	SDL_LockSurface(surfReturn);
	for (int i = 0; i < surfReturn->w; i++)
	{
		for (int j = 0; j < surfReturn->h; j++)
		{
//			printf("%d ", getPixel(surfReturn, i, j));
		}
	}
	SDL_UnlockSurface(surfReturn);
	std::cout << std::endl;

	return surfReturn;
}

bool blitSurface(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
 
    SDL_Rect DestR;
 
    DestR.x = X;
    DestR.y = Y;
 
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
 
    return true;
}


}} //end of namespace
