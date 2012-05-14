
#include <iostream>

#include "Matrix.h"
#include "Vector2.h"
#include "Rectangle.h"
#include "TileBase.h"

using namespace Box;

typedef Vector2<int> Vector2i;
typedef Rectangle<int> Rectanglei;

int main()
{
	std::cout << "Initiating main.." << std::endl;

    Matrix< TileBase<int> > m(10,10);
    
    TileBase<int> *tile1 = new TileBase<int>(Rectanglei(Vector2i(1,6), Vector2i(4,4)));

    m.insertAt(*tile1, 2, 2);
	std::cout << "Tile inserted at 2,2: " << tile1 << std::endl;
    
    delete(tile1);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << m(i,j).position().x << "," << m(i,j).position().y << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Terminating.." << std::endl;

    return 0;
}
