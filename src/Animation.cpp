
#include "Animation.h"

#include <iostream>

namespace Box
{

Animation::Animation(std::string name, ImageBase *framesImage, const Vector2<int> &frameSize, int numFrames)
	: mName(name), mpImage(framesImage), mNumFrames(numFrames), mCurrentFrameIndex(0), mPosition(0,0),
	  mDirection(ANIMATION_DIRECTION_FORWARD), mType(ANIMATION_NONE), mFrames(numFrames)
{
	int numFramesPerRow = mpImage->width() / frameSize.x;

	for (int i = 0; i < mNumFrames; i++)
	{
		int x = (i % numFramesPerRow) * frameSize.x;
		int y = (i / numFramesPerRow) * frameSize.y;

		mFrames[i].box.position(Vector2<int>(x,y)); 
		mFrames[i].box.width(frameSize.x); 
		mFrames[i].box.height(frameSize.y); 
	}
}

Animation::Animation(std::string name, const Vector2<int> &position, ImageBase *framesImage, const Vector2<int> &frameSize, int numFrames)
	: mName(name), mpImage(framesImage), mNumFrames(numFrames), mCurrentFrameIndex(0), mPosition(position),
	  mDirection(ANIMATION_DIRECTION_FORWARD), mType(ANIMATION_NONE), mFrames(numFrames)
{
	int numFramesPerRow = mpImage->width() / frameSize.x;

	for (int i = 0; i < mNumFrames; i++)
	{
		int x = (i % numFramesPerRow) * frameSize.x;
		int y = (i / numFramesPerRow) * frameSize.y;

		mFrames[i].box.position(Vector2<int>(x,y)); 
		mFrames[i].box.width(frameSize.x); 
		mFrames[i].box.height(frameSize.y); 
	}
}

void Animation::nextFrame()
{
	const int lastFrame = mNumFrames - 1;

	switch(mType)
	{
		case ANIMATION_FORWARD_ONLY:
			if (mCurrentFrameIndex != lastFrame)
				mCurrentFrameIndex++;

		break;

		case ANIMATION_LOOPING:
			if (mCurrentFrameIndex == lastFrame)
				mCurrentFrameIndex = 0; //Go to the first frame
			else
				mCurrentFrameIndex++;
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
	mpImage->draw(mPosition, &mFrames[mCurrentFrameIndex].box);
	this->nextFrame();
}

void Animation::animate(const Vector2<int> &position)
{
	mpImage->draw(position, &mFrames[mCurrentFrameIndex].box);
	this->nextFrame();
}

void Animation::addFrame(const Frame &frame)
{
	if (frame.id < 0 || frame.id > mNumFrames)
	{
		throw std::invalid_argument("Can't add frame to animation: frame id not in range");
	}

	mFrames[frame.id] = frame;
}

Animation::TAnimationDirectionEnum Animation::direction() const
{
	return mDirection;
}

void Animation::direction(TAnimationDirectionEnum direction)
{
	mDirection = direction;
}

void Animation::position(const Vector2<int> position)
{
	mPosition = position;
}

} //end of namespace
