
#ifndef TILEBASE_H
#define TILEBASE_H

#include <string>

#include "Vector2.h"
#include "Rectangle.h"

namespace Box
{

template <typename T>
class TileBase
{
public:
	TileBase();
	TileBase(const Rectangle<T> &rectangle);

public:
	Vector2<T> position() const;

protected:
	Rectangle<T> mRectangle;
};

template<typename T>
TileBase<T>::TileBase()
{
	//empty
}

template<typename T>
TileBase<T>::TileBase(const Rectangle<T> &rectangle)
{
	mRectangle = rectangle;
}

template <typename T>
Vector2<T> TileBase<T>::position() const
{
	return mRectangle.position();
}

} //end of namespcae

#endif //TILEBASE_H
