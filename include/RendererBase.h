
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
 * RendererBase.h
 * Base class to define rendering routines for image classes
 *
 * Author: Juliano F. Schroeder
 * Date: 21st May 2012
 * -------------------------------------------------------------------------- */

#ifndef RENDERERBASE_H
#define RENDERERBASE_H

#include "ImageBase.h"
#include "Animation.h"
#include "TileBase.h"
#include "Vector2.h"

namespace Box
{

class RendererBase
{
public:
	/**
	 * \brief Renders the image or throws an exception if it can't.
	 */
	virtual void renderImage(const ImageBase &image, const Vector2i &position) = 0;
	virtual void renderAnimation(const Animation &animation) = 0;
	virtual void renderTile(const Tilei &tile) = 0;
};

} //end of namespace

#endif //RENDERERBASE_H
