
#include "Animation.h"

namespace Box
{

Animation::Animation()
{
	//empty
}

Animation::Animation(ImageBase *framesImage)
	: mpImage(framesImage)
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

Animation::TAnimationDirectionEnum Animation::direction() const
{
	return mDirection;
}

void Animation::direction(TAnimationDirectionEnum direction)
{
	mDirection = direction;
}

} //end of namespace
