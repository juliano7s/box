
#include "Animation.h"

#include <iostream>

namespace Box
{

Animation::Animation()
{
	//empty
}

Animation::Animation(const Vector2<int> &position, ImageBase *framesImage, Vector2<int> frameSize, int numFrames)
	: mpImage(framesImage), mFrameSize(frameSize), mNumFrames(numFrames), mCurrentFrameIndex(0),
	  mDirection(ANIMATION_DIRECTION_FORWARD), mType(ANIMATION_PENDULUM), mPosition(position) 
{
	//empty
}

void Animation::nextFrame()
{
	const int lastFrame = mNumFrames - 1;

	switch(mType)
	{
		case ANIMATION_FORWARD_ONLY:

		break;

		case ANIMATION_LOOPING:

		break;

		case ANIMATION_PENDULUM:
			if (mCurrentFrameIndex == lastFrame)
				mDirection = ANIMATION_DIRECTION_BACKWARD;

			if (mCurrentFrameIndex == 0)
				mDirection = ANIMATION_DIRECTION_FORWARD;

			if (mDirection == ANIMATION_DIRECTION_FORWARD)
				mCurrentFrameIndex++;

			if (mDirection == ANIMATION_DIRECTION_BACKWARD)
				mCurrentFrameIndex--;
		break;

		case ANIMATION_NONE:
		default:
			if (mDirection == ANIMATION_DIRECTION_FORWARD)
			{
				if (mCurrentFrameIndex == lastFrame)
					mCurrentFrameIndex = 0; //Go to the first frame
				else
					mCurrentFrameIndex++;
			} else
			{
				if (mCurrentFrameIndex == 0)
					mCurrentFrameIndex = lastFrame; //Go to the first frame
				else
					mCurrentFrameIndex--;
			}
		break;
	}
}

void Animation::animate()
{
	int numFramesPerRow = mpImage->width() / mFrameSize.x;
	int x = (mCurrentFrameIndex % numFramesPerRow) * mFrameSize.x;
	int y = (mCurrentFrameIndex / numFramesPerRow) * mFrameSize.y;

	Rectangle<int> frameRect(Vector2<int>(x,y), mFrameSize.x, mFrameSize.y);

//	std::cout << "numFramesPerRow " << numFramesPerRow << std::endl;
//	std::cout << "mNumFrames " << mNumFrames << std::endl;
//	std::cout << "mCurrentFrameIndex " << mCurrentFrameIndex << std::endl;
//	std::cout << "mpImage->width() " << mpImage->width() << std::endl;
//	std::cout << "Drawing frame at " << x << "," << y << std::endl;
//	std::cout << "Frame size " << mFrameSize.x << "," << mFrameSize.y << std::endl;

	mpImage->draw(mPosition, &frameRect);
	this->nextFrame();
}

Animation::TAnimationDirectionEnum Animation::direction() const
{
	return mDirection;
}

void Animation::direction(TAnimationDirectionEnum direction)
{
	mDirection = direction;
}

} //end of namespace
