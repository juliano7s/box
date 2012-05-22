
#ifndef IMAGEBASE_H
#define IMAGEBASE_H

#include <string>
#include <stdint.h>

#include "Vector2.h"
#include "Rectangle.h"

namespace Box
{

/* Forward declare RendererBase */
class RendererBase;

class ImageBase
{
public:
	ImageBase() { /* empty */ };

	/**
	 * \brief Creates an image object from a file.
	 */
	ImageBase(std::string fileName) : mFileName(fileName) { /* empty */ };

	/**
	 * \brief Creates an image object from a file. To the image is passed
	 * a reference to a renderer.
	 */
	ImageBase(std::string fileName, RendererBase &renderer)
		: mFileName(fileName), mRenderer(&renderer) { /* empty */ };

public:

	/**
	 * \brief Loads the image data from a file with mFileName
	 */
	virtual void load() = 0;

	/**
	 * \brief Draws the whole image on the specified position
	 */
	virtual void draw(const Vector2<int> &position) { /* empty */ }

	/**
	 * \brief Draws a region of the image passed in the rectangle imageRegion at the specified
	 * 		  position
	 */
	virtual void draw(const Vector2<int> &positionAtScreen, Rectangle<int> *imageRegion) { /* empty */ }

	/* Accessors/Mutators */
	bool isLoaded() const { return mIsLoaded; }
	int width() const { return mPixelWidth; }
	int height() const { return mPixelHeight; }
	uint8_t depth() const { return 8 * mBytesPerPixel; }
	uint16_t pitch() const { return mPitch; }
	void* pixels() const { return mPixels; }
	uint32_t redMask() const { return mRedMask; }
	uint32_t greenMask() const { return mGreenMask; }
	uint32_t blueMask() const { return mBlueMask; }
	uint32_t alphaMask() const { return mAlphaMask; }

protected:
	std::string mFileName;
	RendererBase *mRenderer; //Dependency Injection

	void *mPixels;
	int mPixelWidth, mPixelHeight;
	uint8_t mBytesPerPixel;
	uint16_t mPitch;
	uint32_t mRedMask, mGreenMask, mBlueMask, mAlphaMask;
	bool mIsLoaded;
};

} //end of namespace

#endif //IMAGEBASE_H
