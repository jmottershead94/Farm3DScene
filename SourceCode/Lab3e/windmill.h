// Jason Mottershead, Student Number 1300455.

// Windmill class header file.
// This will contain the hierarchical structure for creating a windmill.
// This will also show off hierarchical animation for the windmill blades.

// Header guards.
#ifndef _WINDMILL_H_
#define _WINDMILL_H_

// Include files here.
//#include "shape.h"
//#include "room.h"
#include "building.h"

// Windmill IS A building, therefore inherits from it.
class Windmill : public Building
{
	public:
		// Attributes.
		float fan_rotation_, scrolling_text_x_;
		
		// Methods.
		Windmill();
		~Windmill();
		void Init();
		void Render(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

	private:
		// Attributes.
		GLuint windmill_base_, windmill_roof_, text_;
		Mesh scrolling_text_;
};

#endif