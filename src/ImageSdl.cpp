
#include "ImageSdl.h"

#include <iostream>
#include <stdexcept>

#include "SDL/SDL_image.h"

#include "SDLUtils.h"

namespace Box
{

ImageSdl::ImageSdl(std::string fileName)
	: ImageBase(fileName)
{
	this->loadImage();
}

/* virtual */ void ImageSdl::loadImage()
{
	SDL_Surface *surfTemp = NULL;

	surfTemp = IMG_Load(mFileName.c_str());
	if (!surfTemp)
	{
		throw std::runtime_error("Error loading image file");
	}

	mSurface = *SDL_DisplayFormat(surfTemp);

	SDLUtils::printSurfaceInfo(mSurface);

	SDL_FreeSurface(surfTemp);

	SDL_LockSurface(&mSurface);
	mPixels = mSurface.pixels;
	SDL_UnlockSurface(&mSurface);

	mBytesPerPixel = mSurface.format->BytesPerPixel;
	mPitch = mSurface.pitch;
	mPixelWidth = mSurface.w;
	mPixelHeight = mSurface.h;
	mIsLoaded = true;
}

} //end of namespace
