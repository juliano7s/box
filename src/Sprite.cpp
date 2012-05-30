
#include "Sprite.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

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
				std::string animationName, fSizex, fSizey, nFrames;

				if (token.compare("U") == 0)
				{
					std::getline(sheetDataFile, animationName, ' ');
					std::getline(sheetDataFile, nFrames, ' ');
					std::getline(sheetDataFile, fSizex, ' ');
					std::getline(sheetDataFile, fSizey, ' ');

					Animation a(animationName, &spriteSheet, Vector2<int>(atoi(fSizex.c_str()), atoi(fSizey.c_str())), atoi(nFrames.c_str()));

					mAnimations.push_back(a);
				}
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
	mAnimations[mCurrentAnimationIndex].animate(mPosition);
}

} //end of namespace
