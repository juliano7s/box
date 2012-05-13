
#include <iostream>

#include "Matrix.h"
#include "Tile.h"

int main()
{
	std::cout << "Initiating main.." << std::endl;

    Box::Matrix<Box::Tile> m(10,10);
    
    Box::Tile *tile1 = new Box::Tile("defaultTile");
	std::cout << "Tile inserted at 2,2: " << tile1 << std::endl;
    m.insertAt(*tile1, 2, 2);
    
    delete(tile1);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
            std::cout << "Element at " << i << "," << j << " : " << &m.elementAt(i,j) << " - " << m.elementAt(i,j).typeName() << std::endl;
		}
	}

	std::cout << "Terminating.." << std::endl;

    return 0;
}
