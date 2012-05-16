
#ifndef VECTOR2_H
#define VECTOR2_H

namespace Box
{

template <typename T>
struct Vector2
{
	T x, y;

	Vector2() : x(0), y(0) { /* empty */ };

	Vector2(const T& x, const T& y)
	{
		this->x = x;
		this->y = y;
	}
};

} //end of namespace

#endif //VECTOR2_H
