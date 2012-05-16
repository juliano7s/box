
#ifndef SDLUTILS_H
#define SDLUTILS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

namespace Box
{
	namespace SDLUtils
	{

Uint32 getPixel(SDL_Surface *surface, int x, int y);
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
int initSDL(SDL_Surface *surface);
void printSurfaceInfo(const SDL_Surface &surface);
SDL_Surface* loadImage(const char *file);

}} //end of namespace

#endif //SDLUTILS_H
