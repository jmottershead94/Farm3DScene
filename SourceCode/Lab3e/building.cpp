#include "building.h"

Building::Building()
{
}

Building::~Building()
{
}

void Building::Init()
{
	red_ = TextureInit("Converted_Textures/red.png");
}

void Building::Render(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, Vec2 interior)
{
	// Setting up the display list.
	building_dlist_ = glGenLists(1);

	// Start of the display list.
	glNewList(building_dlist_, GL_COMPILE);

		// Draws the cube for the building.
		DrawCube(position, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f), true);
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

		// If there is more than 1 room AND 1 floor.
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
						CreateRoom(position, dimensions_, texture_coordinate, texture_dimension);

						// Move the room by a length which is a fraction of the whole building.
						// Using the dimensions calculated above.
						// This will place a room further into the building (z axis).
						glTranslatef(0.0f, 0.0f, -translations_.getX());
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
		// Otherwise, there is only need for 1 of both.
		else
		{
			// Create a room in the intial spot.
			CreateRoom(position, dimensions_, texture_coordinate, texture_dimension);
		}

	// End of the display list.
	glEndList();
}

void Building::CreateRoom(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension)
{
	// Dynamic memory allocation for each room.
	Room* room_ = new Room();
	room_->Render(position, dimension, texture_coordinate, texture_dimension, 3, false, false, false, false, false, false, false, false, false, false, false);
	
	delete room_;
	room_ = NULL;
}

void Building::CreateRoof(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension)
{
	BindTexture(red_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			
	// To the top of the building.
	glPushMatrix();

		// Setting the correct roof coordinates, this sets the first triangle to the correct position.
		Vec3 position_ (position.getX(), position.getY() + dimension.getY(), position.getZ());
		
		// Rotate the triangle to cover the whole roof correctly.
		glRotatef(225.0f, 0.0f, 0.0f, 1.0f);

		// Translate the triangle to position onto the building correctly.
		glTranslatef((-dimension.getX() * 1.4f), (-dimension.getY() * 1.4f), 0.0f);

		// Scaling the triangle down to fit onto the building and look in the correct place.
		glScalef(0.7f, 0.7f, 0.7f);

		// Draw the first roof segment.
		DrawTriangle(position_, dimension, texture_coordinate, texture_dimension);

		// Move the next triangle to the back of the building.
		position_.setZ(position.getZ() - (dimension.getX() * 1.42f));

		// Draw the second roof segment.
		DrawTriangle(position_, dimension, texture_coordinate, texture_dimension);

		// Go to the quads on the roof.
		glPushMatrix();

			// Resetting the position of the quads.
			position_.setZ(position.getZ());

			// Rotating the quad to be in the correct place.
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

			// Scaling the quad to fit in the roof correctly.
			glScalef(1.42f, 1.0f, 1.2f);

			// Draw the third roof segment.
			DrawQuad(position_, dimension, texture_coordinate, texture_dimension , Vec3(0.0f, 1.0f, 0.0f));

			// Scaling the quad to fit in the roof correctly.
			glScalef(1.0f, 1.0f, 0.82f);

			glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

			// Creating another quad segment on the roof.
			position_.setZ(position.getZ() + dimension.getX());
			position_.setY(position.getY() - dimension.getY());
			position_.setX(position.getX() - dimension.getX());
			
			glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

			// Draw the last roof segment.
			DrawQuad(position_, dimension, texture_coordinate, texture_dimension, Vec3(0.0f, 1.0f, 0.0f));

		// Back to the triangle roof segments.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}