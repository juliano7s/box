
#ifndef TILEBASE_H
#define TILEBASE_H

#include <string>

#include "Vector2.h"
#include "Rectangle.h"
#include "ImageBase.h"

namespace Box
{

template <typename T>
class TileBase
{
public:
	TileBase();
	TileBase(const Rectangle<T> &rectangle, std::string imageFile);
	TileBase(const Vector2<T> &position, const Vector2<T> &dimensions);
	TileBase(const Rectangle<T> &rectangle, ImageBase *image) : mpImage(image) { };
	~TileBase() { /* responsible for deleting the mpImage pointer - it owns the pointer */ };

public:
	Vector2<T> position() const;

protected:
	Rectangle<T> mRectangle;
	ImageBase *mpImage;
};

template<typename T>
TileBase<T>::TileBase()
{
	//empty
}

template <typename T>
TileBase<T>::TileBase(const Vector2<T> &position, const Vector2<T> &dimensions)
	: mRectangle(position, dimensions.x, dimensions.y)
{
	
}

template<typename T>
TileBase<T>::TileBase(const Rectangle<T> &rectangle, std::string imageFile)
	: mRectangle(rectangle)
{
	//Use a factory to create the mpImage member with the imageFile parameter
}

template <typename T>
Vector2<T> TileBase<T>::position() const
{
	return mRectangle.position();
}

} //end of namespcae

#endif //TILEBASE_H
