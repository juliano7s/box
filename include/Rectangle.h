
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vector2.h"

#include <stdexcept>

namespace Box
{

template <typename T>
class Rectangle
{
public:
	Rectangle();
	Rectangle(const Vector2<T> &firstPoint, const Vector2<T> &lastPoint);
	Rectangle(const Vector2<T> &position, T width, T height);

public:
	/**
	 * \brief Returns the rectangle origin - the lowest leftmost point (lowest x and y)
	 * */
	Vector2<T> position() const;
	void position(const Vector2<T> &newPosition);
	T width() const;
	T height() const;

private:
	Vector2<T> mFirstPoint, mLastPoint;
};

typedef Rectangle<int> Rectanglei;

/* Constructors */

template <typename T>
Rectangle<T>::Rectangle()
{
	//empty
}

template <typename T>
Rectangle<T>::Rectangle(const Vector2<T> &firstPoint, const Vector2<T> &lastPoint)
{
	if (firstPoint.x == lastPoint.x)
	{
		throw std::invalid_argument("Points make a rectangle with 0 width");
	}

	if (firstPoint.y == lastPoint.y)
	{
		throw std::invalid_argument("Points make a rectangle with 0 height");
	}

	/* Rectangle origin is always the bottom left point (lowest x and lowest y) */
	mFirstPoint.x = (firstPoint.x < lastPoint.x) ? firstPoint.x : lastPoint.x;
	mFirstPoint.y = (firstPoint.y < lastPoint.y) ? firstPoint.y : lastPoint.y;
}

template <typename T>
Rectangle<T>::Rectangle(const Vector2<T> &position, T width, T height)
{
	if (width <= 0)
	{
		throw std::invalid_argument("Can't create a 0 width rectangle");
	}

	if (width <= 0)
	{
		throw std::invalid_argument("Can't create a 0 height rectangle");
	}

	mFirstPoint = position;
	mLastPoint.x = position.x + width;
	mLastPoint.y = position.y + height;
}

/* Methods */

template <typename T>
Vector2<T> Rectangle<T>::position() const
{
	return mFirstPoint;
}

template <typename T>
void Rectangle<T>::position(const Vector2<T> &newPosition)
{
	mFirstPoint = newPosition;
	mLastPoint.x = mFirstPoint + this->width();
	mLastPoint.y = mFirstPoint + this->height();
}

template <typename T>
T Rectangle<T>::width() const
{
	return (mLastPoint.x - mFirstPoint.x);
}

template <typename T>
T Rectangle<T>::height() const
{
	return (mLastPoint.y - mFirstPoint.y);
}

} //end of namespace

#endif //RECTANGLE_H
