
/* -----------------------------------------------------------------------------
 * This software is thought out with these guidelines:
 *
 * - Don't solve problems that don't need to be solved.
 * - Don't worry about the future until you're sure you can survive the present.
 * - Build things for the fun of it.
 * - Don't add risk without a compelling and measurable benefit to the project.
 * - Don't invest in the future if your current project is in trouble.
 *
 *                                                   - Source: C++ FAQ
 *
 * Sprite.h
 * Sprite class defines an object that:
 *  - is shown on the screen
 *  - can move
 *  - can have multiple animations
 *  - cannot interact with a physics system (put it on an Entity class)
 *  - cannot have an AI (put it on an Entity class)
 *
 * Author: Juliano F. Schroeder
 * Date: 21st May 2012
 * -------------------------------------------------------------------------- */

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <vector>
#include <map>

#include "ImageBase.h"
#include "Animation.h"
#include "Vector2.h"

namespace Box
{

class Sprite
{
public:

	/**
	 * \brief Creates a Sprite based on a spriteSheet image and datafile
	 */
	Sprite(ImageBase &spriteSheet, std::string sheetDataFileName);

	/**
	 * \brief Changes the sprite position to a new position
	 */
	void move(const Vector2<int> &position);

	/**
	 * \brief Calls the current animation animate() function passing the sprite position
	 */
	void show();

private:
	ImageBase *mpSpriteSheet;
	std::vector<Animation> mAnimations;
	int mCurrentAnimationIndex;
	Vector2<int> mPosition;
};

} //end of namespace

#endif //SPRITE_H
