
#include "Sprite.h"

#include <iostream>
#include <fstream>
#include <string>

namespace Box
{

Sprite::Sprite(ImageBase &spriteSheet, std::string sheetDataFileName)
	: mpSpriteSheet(&spriteSheet), mCurrentAnimationIndex(0), mPosition(0,0)
{
	std::ifstream sheetDataFile(sheetDataFileName.c_str());
	if (sheetDataFile.is_open())
	{
		std::cout << "Opening sprite sheet data file: " << sheetDataFileName << std::endl;
		while (sheetDataFile.good())
		{
			std::string token;
			while (std::getline(sheetDataFile, token, ' '))
			{
				std::cout << token << std::endl;
			}
		}

		sheetDataFile.close();
	} else
	{
		std::cout << "Unable to open sprite sheet data file" << std::endl;
	}
}

void Sprite::move(const Vector2<int> &position)
{
	mPosition = position;
}

void Sprite::show()
{

}

} //end of namespace
