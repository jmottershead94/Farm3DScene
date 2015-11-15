// Jason Mottershead, Student Number 1300455.

// House living room class header file.
// This class will contain all of the specific things inside of this room.

// Header guard.
#ifndef _HOUSE_LIVINGROOM_H_
#define _HOUSE_LIVINGROOM_H_

// Include files here.
#include "room.h"

// House livingroom IS A room, therefore it inherits from room.
class HouseLivingRoom : public Room
{
	public:
		// Methods.
		HouseLivingRoom();
		~HouseLivingRoom();
		void Init();
		void Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor);
};

#endif