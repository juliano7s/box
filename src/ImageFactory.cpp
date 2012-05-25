
#include "ImageFactory.h"

#include <stdexcept>
#include <utility>
#include <iostream>

#include "ImageSdl.h"

namespace Box
{

ImageFactory::ImageFactory()
	: mImageMap()
{
	//empty
}

ImageFactory::ImageFactory(RendererBase &renderer)
	: mImageMap(), mRenderer(&renderer)
{
	//empty
}

ImageFactory::~ImageFactory()
{
	for (TImageContainer::iterator it = mImageMap.begin(), end = mImageMap.end(); it != end; ++it)
	{
		release(it->first);
	}
}

ImageBase* ImageFactory::createInstance(std::string imageFile, TImageEnum imageType = IMAGE_DEFAULT)
{
	ImageBase *createdImage = NULL;

	switch (imageType)
	{
		case IMAGE_DEFAULT:
		case IMAGE_SDL:
			if (mRenderer != NULL)
				createdImage = new ImageSdl(imageFile, *mRenderer);
			else
				createdImage = new ImageSdl(imageFile);
		break;

		case IMAGE_FREE:
		default:
			throw std::invalid_argument("Image type invalid or not yet implemented");
		break;
	}

	if (createdImage == NULL)
		throw std::runtime_error("Error loading image");

	return createdImage;
}

ImageBase* ImageFactory::acquire(std::string imageFile)
{
	ImageBase *image = NULL;

	if (mImageMap[imageFile] != NULL)
	{
		image = mImageMap[imageFile];
	} else
	{
		image = createInstance(imageFile);
		mImageMap.insert(std::pair< std::string, ImageBase* >(imageFile, image));
	}

	return image;
}

void ImageFactory::release(std::string imageFile)
{
	delete(mImageMap[imageFile]);
}

} //end of namespace
