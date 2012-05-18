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
	~ImageFactory();

	ImageBase *createInstance(std::string imageFile, TImageEnum imageType);
	ImageBase *acquire(std::string imageFile);
	void release(std::string imageFile);
	
private:
	TImageContainer mImageMap;

};

} //end of namespace

#endif //IMAGEFACTORY_H
