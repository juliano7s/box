/* -----------------------------------------------------------------------------
 * This software is fake tales of San Francisco that echoes through the room.
 * I bet that it looks good on the dance floor, and I don't know if it is
 * looking for romance or and I don't know what it is looking for.
 *
 * ImageFactory.h
 * Factory/Pool for objects of type Box::ImageBase
 *
 * Author: Juliano F. Schroeder
 * Date: 17th May 2012
 * -------------------------------------------------------------------------- */

#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H

#include <string>
#include <map>

#include "ImageBase.h"
#include "RendererBase.h"

namespace Box
{

class ImageFactory
{
public:

	typedef std::map< std::string, ImageBase* > TImageContainer;

	typedef enum
	{
		IMAGE_DEFAULT = 0,
		IMAGE_SDL,
		IMAGE_FREE,
	} TImageEnum;

	ImageFactory();
	ImageFactory(RendererBase &renderer);
	~ImageFactory();

	/**
	 * \brief Creates an Image instance and abandon its ownership
	 */
	ImageBase *createInstance(std::string imageFile, TImageEnum imageType);

	/**
	 * \brief Creates an Image instance and keep its ownership. The instance can be
	 *        deleted with a call to ImageFactory::release()
	 */
	ImageBase *acquire(std::string imageFile);

	/**
	 * \brief Deletes reference for the object created for the given image file
	 */
	void release(std::string imageFile);

	void renderer(RendererBase &renderer) { mRenderer = &renderer; }

private:
	TImageContainer mImageMap;
	RendererBase *mRenderer;

};

} //end of namespace

#endif //IMAGEFACTORY_H
