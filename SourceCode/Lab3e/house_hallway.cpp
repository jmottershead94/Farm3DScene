#include "house_hallway.h"

HouseHallway::HouseHallway()
{
}

HouseHallway::~HouseHallway()
{
}

void HouseHallway::Init()
{
	// Initialising textures.
	fabric_rough_carpet_ = TextureInit("Converted_Textures/fabric_rough_carpet.png");
	painting_river_ = TextureInit("Converted_Textures/painting_river.jpg");
	
	// Initialising the room.
	Room::Init();
}

void HouseHallway::Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, bool no_floor)
{
	//			(x, y, z), (w, h),    (u, v),			, (w, h)		   ,  , reflect , front, left, back, right, frontw, leftw, backw, rightw, up, down. 
	Room::Render(position, dimension, texture_coordinate, texture_dimension, 3, no_floor, true, true, true, false, false, false, false, false, true, false);
	
	// Draw the rest of the room here.
	// Inside of the room.
	glPushMatrix();

		// To the floor.
		glPushMatrix();
			
			BindTexture(fabric_rough_carpet_, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
			glTranslatef(0.0f, 0.125f, -dimension.getX());
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			DrawPlane(position, dimension, texture_coordinate, texture_dimension, Vec3(1.0f, 1.0f, 1.0f), 4);

		// Back to the back room.
		glPopMatrix();

		// To the hallway painting.
		glPushMatrix();

			glTranslatef(-1.5f, 6.0f, -8.5f);
			glScalef(1.5f, 1.5f, 1.5f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			CreatePainting(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension, "Converted_Textures/painting_river.jpg");

		// Back to the hallway.
		glPopMatrix();

		// To the table.
		glPushMatrix();

			glTranslatef((dimension.getX() / 2.0f) - 2.0f, 0.0f, (-dimension.getX() / 2.0f) + 1.0f);
			glScalef(0.5f, 0.875f, 0.375f);
			CreateTable(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the hallway.
		glPopMatrix();
				
		// To the lamp.
		glPushMatrix();
			
			glTranslatef((dimension.getX() / 2.0f) - 1.0f, 2.25f, (-dimension.getX() / 2.0f));
			glScalef(0.25f, 0.25f, 0.25f);
			CreateLamp(position, Vec2(1.0f, 1.0f), texture_coordinate, texture_dimension);

		// Back to the hallway.
		glPopMatrix();

	// Back to the original 3D scene.
	glPopMatrix();
}
