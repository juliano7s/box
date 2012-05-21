
#ifndef IMAGEBASE_H
#define IMAGEBASE_H

#include <string>
#include <stdint.h>

namespace Box
{

class ImageBase
{
public:
	ImageBase() { /* empty */ };
	ImageBase(std::string fileName) : mFileName(fileName) { /* empty */ };

public:
	virtual void load() = 0;
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
	void *mPixels;
	int mPixelWidth, mPixelHeight;
	uint8_t mBytesPerPixel;
	uint16_t mPitch;
	uint32_t mRedMask, mGreenMask, mBlueMask, mAlphaMask;
	bool mIsLoaded;
};

} //end of namespace

#endif //IMAGEBASE_H
