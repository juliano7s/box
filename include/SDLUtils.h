
#ifndef SDLUTILS_H
#define SDLUTILS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "ImageBase.h"
#include "TileBase.h"

namespace Box
{
	namespace SDLUtils
	{

Uint32 getPixel(SDL_Surface *surface, int x, int y);
void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
SDL_Surface* initSDL(void);
void printSurfaceInfo(const SDL_Surface &surface);
SDL_Surface* load(const char *file);

/**
 * \brief creates a surface that needs to be freed later with SDL_FreeSurface
 */
SDL_Surface* createSurface(const ImageBase &image);
bool blitSurface(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
void drawTileOnSurface(const TileBase<int> &tile, SDL_Surface *surface);

}} //end of namespace

#endif //SDLUTILS_H
