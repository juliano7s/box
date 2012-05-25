
#include "ImageSdl.h"

#include <iostream>
#include <stdexcept>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "SDLUtils.h"
#include "RendererBase.h"

namespace Box
{

ImageSdl::ImageSdl(std::string fileName)
	: ImageBase(fileName)
{
	this->load();
}

ImageSdl::ImageSdl(std::string fileName, RendererBase &renderer)
	: ImageBase(fileName, renderer)
{
	this->load();
}

void ImageSdl::load()
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
	mRedMask = mSurface.format->Rmask;
	mGreenMask = mSurface.format->Gmask;
	mBlueMask = mSurface.format->Bmask;
	mAlphaMask = mSurface.format->Amask;
	mIsLoaded = true;
}

void ImageSdl::draw(const Vector2<int> &position)
{
	if (mRenderer != NULL)
		mRenderer->renderImage(*this, position, NULL);
}

void ImageSdl::draw(const Vector2<int> &positionAtScreen, Rectangle<int> *imageRegion)
{
	if (mRenderer != NULL)
		mRenderer->renderImage(*this, positionAtScreen, imageRegion);
}

} //end of namespace
