// Jason Mottershead, Student Number 1300455.

// House class header file.
// This will contain all of the rooms with specific things inside of them.

// Header guard.
#ifndef _HOUSE_H_
#define _HOUSE_H_

// Include files here.
#include "room_id.h"
#include "house_backroom.h"
#include "house_bathroom.h"
#include "house_bedroom.h"
#include "house_hallway.h"
#include "house_kitchen.h"
#include "house_landing.h"
#include "house_livingroom.h"
#include "house_masterbedroom.h"
#include "building.h"

// House IS A building, therefore inherits from building.
class House : public Building
{
	public:
		// Attributes.
		GLuint house_displaylist_;
		Room default_room_;
		HouseLivingRoom livingroom_;
		HouseBackroom backroom_;
		HouseHallway hallway_;
		HouseKitchen kitchen_;
		HouseMasterBedroom master_bedroom_;
		HouseBedroom bedroom_;
		HouseLanding landing_;
		HouseBathroom bathroom_;

		// Methods.
		House();
		~House();
		void Render(Vec3 position, Vec2 dimension, Vec2 texture_coordinates, Vec2 texture_dimension, Vec2 interior);
		void Init();

		// Pass in an ID for rooms to determine which kind of room to create?
		void CreateRoom(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, RoomID room, int room_number);

		void UpdateRoomType(RoomID& room, int& room_number);

};

#endif