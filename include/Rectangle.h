
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vector2.h"

#include <stdexcept>
#include <iostream>

namespace Box
{

template <typename T>
class Rectangle
{
public:
	Rectangle();
	Rectangle(const Vector2<T> &firstPoint, const Vector2<T> &lastPoint);
	Rectangle(const Vector2<T> &position, T width, T height);
	Rectangle(T x, T y, T width, T height);

public:
	/**
	 * \brief Returns the rectangle origin - the lowest leftmost point (lowest x and y)
	 * */
	Vector2<T> position() const;
	void position(const Vector2<T> &newPosition);
	T width() const;
	void width(T width);
	T height() const;
	void height(T height);

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
		std::cerr << "WARNING: 0 height rectangle" << std::endl;
	}

	if (firstPoint.y == lastPoint.y)
	{
		std::cerr << "WARNING: 0 width rectangle" << std::endl;
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
		std::cerr << "WARNING: 0 width rectangle" << std::endl;
	}

	if (height <= 0)
	{
		std::cerr << "WARNING: 0 height rectangle" << std::endl;
	}

	mFirstPoint = position;
	mLastPoint.x = position.x + width;
	mLastPoint.y = position.y + height;
}

template <typename T>
Rectangle<T>::Rectangle(T x, T y, T width, T height)
{
	if (width <= 0)
	{
		std::cerr << "WARNING: 0 width rectangle" << std::endl;
	}

	if (height <= 0)
	{
		std::cerr << "WARNING: 0 height rectangle" << std::endl;
	}

	mFirstPoint.x = x;
	mFirstPoint.y = y;
	mLastPoint.x = x + width;
	mLastPoint.y = y + height;
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
	mLastPoint.x = mFirstPoint.x + this->width();
	mLastPoint.y = mFirstPoint.y + this->height();
}

template <typename T>
T Rectangle<T>::width() const
{
	return (mLastPoint.x - mFirstPoint.x);
}

template <typename T>
void Rectangle<T>::width(T width)
{
	mLastPoint.x = mFirstPoint.x + width;
}

template <typename T>
T Rectangle<T>::height() const
{
	return (mLastPoint.y - mFirstPoint.y);
}

template <typename T>
void Rectangle<T>::height(T height)
{
	mLastPoint.y = mFirstPoint.y + height;
}

} //end of namespace

#endif //RECTANGLE_H
