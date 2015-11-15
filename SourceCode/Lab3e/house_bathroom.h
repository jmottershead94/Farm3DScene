// Jason Mottershead, Student Number 1300455.

// House bath room class header file.
// This class will contain all of the specific things inside of this room.

// Header guard.
#ifndef _HOUSE_BATHROOM_H_
#define _HOUSE_BATHROOM_H_

// Include files here.
#include "room.h"

// House bathroom IS A room, therefore it inherits from room.
class HouseBathroom : public Room
{
	public:
		// Methods.
		HouseBathroom();
		~HouseBathroom();
		void Init();
		void Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor);
};

#endif