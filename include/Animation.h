
/* -----------------------------------------------------------------------------
 * This software is fake tales of San Francisco that echoes through the room.
 * I bet that it looks good on the dance floor, and I don't know if it is
 * looking for romance or and I don't know what it is looking for.
 *
 * Animation.h
 * Class that controls a sequence of frames to create an animation
 *
 * Author: Juliano F. Schroeder
 * Date: 18th May 2012
 * -------------------------------------------------------------------------- */

#ifndef ANIMATION_H
#define ANIMATION_H

namespace Box
{

class Animation
{

public:
	typedef enum
	{
		ANIMATION_NONE = 0      // Follows the direction set on the animation object
		ANIMATION_FORWARD_ONLY, // Animate one time from the first frame to the last
		ANIMATION_LOOPING,      // Loops through the frames in a circular way (1 2 3 4 5 -> 1 2 3 4 5)
		ANIMATION_PENDULUM,     // Loops through the frames back and forth (1 2 3 4 5 4 3 2 1)
	} TAnimationEnum;

	typedef enum
	{
		ANIMATION_DIRECTION_FORWARD,  // steps through frames from id 0 to mNumFrames
		ANIMATION_DIRECTION_BACKWARD, // steps through frames from mNumFrames to 0
	} TAnimationDirectionEnum;

	Animation();
	Animation(ImageBase *framesImage);

	void nextFrame();
	TAnimationDirectionEnum direction() const;
	void direction(TAnimationDirectionEnum direction);

private:
	ImageBase *mpImage;
	Vector2<int> mFrameSize;
	int mCurrentFrameIndex;
	int mNumFrames;
	float mSpeed;
	int mDirection;
};

} //end of namespace

#endif //ANIMATION_H
