// Jason Mottershead, Student Number 1300455.

// House bedroom class header file.
// This class will contain all of the specific things inside of this room.

// Header guard.
#ifndef _HOUSE_BEDROOM_H_
#define _HOUSE_BEDROOM_H_

// Include files here.
#include "model.h"
#include "room.h"

// House bedroom IS A room, therefore it inherits from room.
class HouseBedroom : public Room
{
	public:
		// Methods.
		HouseBedroom();
		~HouseBedroom();
		void Init();
		void Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor);

	private:
		Model chocobo_;
};

#endif