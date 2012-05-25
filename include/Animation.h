
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

#include <vector>
#include <string>

#include "ImageBase.h"
#include "Vector2.h"

namespace Box
{

struct Frame
{
	Frame()
		: id(0), box(0,0,0,0) { /* empty */ }

	Frame(int id, const Vector2<int> position, const Vector2<int> dimension)
		: id(id), box(position, dimension) { /* empty */ }

	int id; 			// Id definig the index of the frame in an animation sequence
	Rectangle<int> box; // Rectangle defining frame position and dimension inside a sprite sheet
};

class Animation
{

public:
	typedef enum
	{
		ANIMATION_NONE = 0,     // Loops through frames following the attribute mDirection
		ANIMATION_FORWARD_ONLY, // Loops one time from the first frame to the last
		ANIMATION_LOOPING,      // Loops through frames in a circular way (1 2 3 4 5 -> 1 2 3 4 5)
		ANIMATION_PENDULUM,     // Loops through frames back and forth (1 2 3 4 5 4 3 2 1)
	} TAnimationEnum;

	typedef enum
	{
		ANIMATION_DIRECTION_FORWARD,  // steps through frames from id 0 to mNumFrames
		ANIMATION_DIRECTION_BACKWARD, // steps through frames from mNumFrames to 0
	} TAnimationDirectionEnum;

	Animation(std::string name, ImageBase *framesImage);
	Animation(std::string name, ImageBase *framesImage, const Vector2<int> &frameSize, int numFrames);
	Animation(std::string name, const Vector2<int> &position, ImageBase *framesImage, const Vector2<int> &frameSize, int numFrames);

	/**
	 * \brief Goes to the next frame based on the animation type mType
	 */
	void nextFrame();

	/**
	 * \brief Draws current frame and goes to the next
	 */
	void animate();

	/**
	 * \brief Draws current frame on the passed position and goes to the next
	 */
	void animate(const Vector2<int> &position);

	/**
	 * \brief Adds a frame to the animation on the place defined by frame.id
	 */
	void addFrame(const Frame &frame);

	TAnimationDirectionEnum direction() const;
	void direction(TAnimationDirectionEnum direction);
	void position(Vector2<int> position);

private:
	std::string mName;
	ImageBase *mpImage;
	int mNumFrames;
	int mCurrentFrameIndex;
	Vector2<int> mPosition;
	TAnimationDirectionEnum mDirection;
	TAnimationEnum mType;
	std::vector<Frame> mFrames;
};

} //end of namespace

#endif //ANIMATION_H
