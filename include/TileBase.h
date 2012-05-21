
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
	typedef int TTileId;
	typedef enum
	{
		TILE_TYPE_NONE = 0,
		TILE_TYPE_FLOOR,
	} TTileEnum;

	TileBase();
	TileBase(const Vector2<T> &position, const Vector2<T> &dimensions);
	TileBase(const Vector2<T> &position, const Vector2<T> &dimensions, ImageBase *image);
	TileBase(const Rectangle<T> &rectangle, ImageBase *image) : mpImage(image) { };
	~TileBase() { };

	Vector2<T> position() const;
	ImageBase* image() const;

protected:
	Rectangle<T> mRectangle;
	ImageBase *mpImage;
	TTileEnum mType;
	TTileId mId; //Id that defines a block inside mpImage
};

template<typename T>
TileBase<T>::TileBase()
{
	//empty
}

template <typename T>
TileBase<T>::TileBase(const Vector2<T> &position, const Vector2<T> &dimensions, ImageBase *image)
	: mRectangle(position, dimensions.x, dimensions.y), mpImage(image)
{
	
}

template <typename T>
TileBase<T>::TileBase(const Vector2<T> &position, const Vector2<T> &dimensions)
	: mRectangle(position, dimensions.x, dimensions.y)
{
	
}

template <typename T>
Vector2<T> TileBase<T>::position() const
{
	return mRectangle.position();
}

template <typename T>
ImageBase* TileBase<T>::image() const
{
	return mpImage;
}

} //end of namespcae

#endif //TILEBASE_H
