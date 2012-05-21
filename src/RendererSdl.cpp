
#include "RendererSdl.h"

#include "SDLUtils.h"

namespace Box
{

RendererSdl::RendererSdl()
	: mSurface(NULL)
{
	//empty
}


RendererSdl::RendererSdl(SDL_Surface *surface)
	: mSurface(surface)
{
	//empty
}

void RendererSdl::renderImage(const ImageBase &image, const Vector2i &position)
{
	SDL_Surface *imgSurface = SDLUtils::createSurface(image);
	SDLUtils::blitSurface(mSurface, imgSurface, position.x, position.y);
	SDL_FreeSurface(imgSurface);
}

void RendererSdl::renderAnimation(const Animation &animation)
{

}

void RendererSdl::renderTile(const Tilei &tile)
{
	renderImage(*tile.image(), tile.position());
}

} //end of namespace
