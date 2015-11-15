#include "house.h"

House::House()
{
}

House::~House()
{
}

void House::Init()
{
	// Loading in the textures for each of the rooms.
	livingroom_.Init();
	backroom_.Init();
	hallway_.Init();
	kitchen_.Init();
	master_bedroom_.Init();
	bedroom_.Init();
	landing_.Init();
	bathroom_.Init();

	// Initialising the building.
	Building::Init();
}

void House::Render(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec2 interior)
{
	// Setting up the display list.
	house_displaylist_ = glGenLists(1);

	// Start of the display list.
	glNewList(house_displaylist_, GL_COMPILE);

		// Setting the enum up for cycling through different rooms.
		int room_number_ = 0;
		RoomID room_type_ = livingRoom;

		// Draws the roof for the building.
		CreateRoof(position, dimension, texture_coordinate, texture_dimension);

		// Calculating the width and height of the quads for the rooms inside of the building.
		// To make sure the rooms are not bigger than the building.
		// This will set the rooms to an equal size.
		dimensions_.setX(dimension.getX() / interior.getX());
		dimensions_.setY(dimension.getY() / interior.getX());

		// The correct values for translation for multiple floors.
		Vec2 translations_ ((dimension.getX() / interior.getX()), (dimension.getY() / interior.getY()));

		// This is here so that the textured rooms for not "z-fight" with the building.
		glTranslatef(0.1f, 0.1f, -0.1f);
		glScalef(0.99f, 0.99f, 0.99f);

		if(interior.getX() > 1.0f && interior.getY() > 1.0f)
		{
			// For each room that is required.
			// Allows me to move the room along the y axis.
			for(int room_increment_y = 0; room_increment_y < (int)interior.getY(); room_increment_y++)
			{
				// Allows me to move the room along the x axis.
				for(int room_increment_x = 0; room_increment_x < (int)interior.getX(); room_increment_x++)
				{
					// Allows me to move the room along the z axis.
					for(int room_increment_z = 0; room_increment_z < (int)interior.getX(); room_increment_z++)
					{
						// Create a room in the intial spot.
						CreateRoom(position, dimensions_, texture_coordinate, texture_dimension, room_type_, room_number_++);

						// Move the room by a length which is a fraction of the whole building.
						// Using the dimensions calculated above.
						// This will place a room further into the building (z axis).
						glTranslatef(0.0f, 0.0f, -translations_.getX() - 0.01f);
					}

					// Move the translations back on the Z AXIS to the original position.
					// Using the dimensions passed in above.
					glTranslatef(0.0f, 0.0f, dimension.getX());
			
					// Move the room by a width which is a fraction of the whole building.
					// This will place each room side by side (x axis).
					glTranslatef((translations_.getX() + 0.001f), 0.0f, 0.0f);
				}
	
				// Move the translations back on the X AXIS to the original position.
				// Using the dimensions passed in above.
				glTranslatef(-dimension.getX(), 0.0f, 0.0f);

				// Move the room by a height which is a fraction of the whole building.
				// This will place each room on top of each other (y axis).
				glTranslatef(0.0f, translations_.getY() + 0.001f, 0.0f);
			}

			// Move the translations back on the Y AXIS to the original position.
			// Using the dimensions passed in above.
			glTranslatef(0.0f, dimension.getY(), 0.0f);
		}
		else
		{
			// Create a room in the intial spot.
			CreateRoom(position, dimensions_, texture_coordinate, texture_dimension, room_type_, room_number_++);
		}

	// End of the display list.
	glEndList();
}

void House::CreateRoom(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, RoomID room, int room_number)
{
	// Decides what room id to use.
	UpdateRoomType(room, room_number);

	// Cycling through the room types.
	switch(room)
	{
		// If the room needed is a living room.
		case livingRoom:
		{
			// Render the living room.
			livingroom_.Render(position, dimension, texture_coordinate, texture_dimension, false);
			break;
		}
		
		// If the room needed is a back room.
		case backRoom:
		{
			// Render the back room.
			backroom_.Render(position, dimension, texture_coordinate, texture_dimension, false);
			break;
		}
		
		// If the room needed is a hallway.
		case hallway:
		{
			// Render the hallway.
			hallway_.Render(position, dimension, texture_coordinate, texture_dimension, false);
			break;
		}
		
		// If the room needed is a kitchen.
		case kitchen:
		{
			// Render the kitchen.
			kitchen_.Render(position, dimension, texture_coordinate, texture_dimension, true);
			break;
		}
		
		// If the room needed is a master bedroom.
		case masterBedRoom:
		{
			// Render the master bedroom.
			master_bedroom_.Render(position, dimension, texture_coordinate, texture_dimension, false);
			break;
		}
		
		// If the room needed is a bedroom.
		case bedRoom:
		{
			// Render the bedroom.
			bedroom_.Render(position, dimension, texture_coordinate, texture_dimension, false);
			break;
		}
		
		// If the room needed is a bath room.
		case bathRoom:
		{
			// Render the bathroom.
			bathroom_.Render(position, dimension, texture_coordinate, texture_dimension, false);
			break;
		}
		
		// If the room needed is a landing.
		case landing:
		{
			// Render the landing.
			landing_.Render(position, dimension, texture_coordinate, texture_dimension, false);
			break;
		}

		// If none of the above rooms are found.
		default:
		{
			// Just ignore the default statement and render nothing.
			break;
		}
	};
}

void House::UpdateRoomType(RoomID& room, int& room_number)
{
	// Check to see if the room number is increasing.
	// Used to render the rooms in the order wanted.
	if(room_number == 0)
	{
		room = livingRoom;
	}
	else if(room_number == 1)
	{
		room = backRoom;
	}
	else if(room_number == 2)
	{
		room = hallway;
	}
	else if(room_number == 3)
	{
		room = kitchen;
	}
	else if(room_number == 4)
	{
		room = masterBedRoom;
	}
	else if(room_number == 5)
	{
		room = bedRoom;
	}
	else if(room_number == 6)
	{
		room = landing;
	}
	else if(room_number == 7)
	{
		room = bathRoom;
	}
}