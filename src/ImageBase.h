
#ifndef IMAGEBASE_H
#define IMAGEBASE_H

#include <string>

namespace Box
{

class ImageBase
{
public:
	ImageBase() { /* empty */ };
	ImageBase(std::string fileName) : mFileName(fileName) { /* empty */ };

public:
	virtual void loadImage() = 0;
	bool isLoaded() const { return mIsLoaded; }
	int width() const { return mPixelWidth; }
	int height() const { return mPixelHeight; }
	unsigned char depth() const { return 8 * mBytesPerPixel; }
	unsigned short pitch() const { return mPitch; }
	void* pixels() const { return mPixels; }

protected:
	std::string mFileName;
	void *mPixels;
	int mPixelWidth, mPixelHeight;
	unsigned char mBytesPerPixel;
	unsigned short mPitch;
	unsigned long mRedMask, mGreenMask, mBlueMask, mAlphaMask;
	bool mIsLoaded;
};

} //end of namespace

#endif //IMAGEBASE_H
