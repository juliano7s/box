
#ifndef IMAGESDL_H
#define IMAGESDL_H

#include "ImageBase.h"

#include "SDL/SDL.h"

namespace Box
{

class ImageSdl
	: public ImageBase
{
public:
	ImageSdl() { /* empty */ }
	ImageSdl(std::string imageFile, RendererBase &renderer);
	ImageSdl(std::string fileName);

public:
	void load();
	void draw(const Vector2<int> &position);
	void draw(const Vector2<int> &positionAtScreen, Rectangle<int> *imageRegion);

private:
	SDL_Surface mSurface;
};

} //end of namespace

#endif //IMAGESDL_H
