
#ifndef RENDERERSDL_H
#define RENDERERSDL_H

#include "SDL/SDL.h"

#include "RendererBase.h"
#include "ImageBase.h"

namespace Box
{

class RendererSdl
	: public RendererBase
{
public:
	RendererSdl();
	RendererSdl(SDL_Surface *surface);

	void surface(SDL_Surface *surface) { mSurface = surface; }
	void renderImage(const ImageBase &image, const Vector2i &position, Rectangle<int> *imageRegion);
	void renderAnimation(const Animation &animation);
	void renderTile(const Tilei &tile);

private:
	SDL_Surface *mSurface;
};

} //end of namespace

#endif //RENDERERSDL_H
